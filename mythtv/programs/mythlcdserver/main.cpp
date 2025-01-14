/*
    main.cpp

    Starting point for the myth lcd server daemon

*/

#include <csignal>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include <QtGlobal>
#include <QCoreApplication>
#include <QFile>

#include "exitcodes.h"
#include "mythcontext.h"
#include "mythdbcon.h"
#include "loggingserver.h"
#include "mythlogging.h"
#include "mythversion.h"
#include "tv_play.h"
#include "compat.h"
#include "mythtranslation.h"
#include "commandlineparser.h"
#include "signalhandling.h"

#include "lcdserver.h"

int main(int argc, char **argv)
{
    int  special_port = -1;
    QString startup_message = "";          // default to no startup message
    std::chrono::seconds message_time = 30s; // time to display startup message

    // TODO: check if this can use LOG_*
    debug_level = 0;  // don't show any debug messages by default

    MythLCDServerCommandLineParser cmdline;
    if (!cmdline.Parse(argc, argv))
    {
        cmdline.PrintHelp();
        return GENERIC_EXIT_INVALID_CMDLINE;
    }

    if (cmdline.toBool("showhelp"))
    {
        cmdline.PrintHelp();
        return GENERIC_EXIT_OK;
    }

    if (cmdline.toBool("showversion"))
    {
        MythLCDServerCommandLineParser::PrintVersion();
        return GENERIC_EXIT_OK;
    }

    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName(MYTH_APPNAME_MYTHLCDSERVER);

    int retval = cmdline.Daemonize();
    if (retval != GENERIC_EXIT_OK)
        return retval;

    bool daemonize = cmdline.toBool("daemon");
    QString mask("general");
    if ((retval = cmdline.ConfigureLogging(mask, daemonize)) != GENERIC_EXIT_OK)
        return retval;

    if (cmdline.toBool("port"))
    {
        special_port = cmdline.toInt("port");
        if (special_port < 1 || special_port > 65534)
        {
            LOG(VB_GENERAL, LOG_ERR, "lcdserver: Bad port number");
            return GENERIC_EXIT_INVALID_CMDLINE;
        }
    }
    if (cmdline.toBool("message"))
        startup_message = cmdline.toString("message");
    if (cmdline.toBool("messagetime"))
    {
        message_time = std::chrono::seconds(cmdline.toInt("messagetime"));
        if (message_time < 1s || message_time > 1000s)
        {
            LOG(VB_GENERAL, LOG_ERR, "lcdserver: Bad message duration");
            return GENERIC_EXIT_INVALID_CMDLINE;
        }
    }
    if (cmdline.toBool("debug"))
    {
        debug_level = cmdline.toInt("debug");
        if (debug_level < 0 || debug_level > 10)
        {
            LOG(VB_GENERAL, LOG_ERR, "lcdserver: Bad debug level");
            return GENERIC_EXIT_INVALID_CMDLINE;
        }
    }

#ifndef _WIN32
    QList<int> signallist;
    signallist << SIGINT << SIGTERM << SIGSEGV << SIGABRT << SIGBUS << SIGFPE
               << SIGILL;
#ifndef Q_OS_DARWIN
    signallist << SIGRTMIN;
#endif
    SignalHandler::Init(signallist);
    SignalHandler::SetHandler(SIGHUP, logSigHup);
#endif

    //  Get the MythTV context and db hooks
    gContext = new MythContext(MYTH_BINARY_VERSION);
    if (!gContext->Init(false))
    {
        LOG(VB_GENERAL, LOG_ERR,
            "lcdserver: Could not initialize MythContext. Exiting.");
        SignalHandler::Done();
        return GENERIC_EXIT_NO_MYTHCONTEXT;
    }

    MythTranslation::load("mythfrontend");

    gCoreContext->ConnectToMasterServer(false);

    //  Figure out port to listen on
    int assigned_port = gCoreContext->GetNumSetting("LCDServerPort", 6545);
    if (special_port > 0)
    {
        assigned_port = special_port;
    }

    auto *server = new LCDServer(assigned_port, startup_message, message_time);

    QCoreApplication::exec();

    delete server;
    delete gContext;

    SignalHandler::Done();

    return GENERIC_EXIT_OK;
}
