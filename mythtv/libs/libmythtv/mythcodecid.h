#ifndef _MYTH_CODEC_ID_H_
#define _MYTH_CODEC_ID_H_

#include <QString>
extern "C"
{
#include "libavcodec/avcodec.h"
}

typedef enum
{
// if you add anything to this list please update
// myth2av_codecid and get_encoding_type
    kCodec_NONE = 0,

    kCodec_NORMAL_BEGIN = kCodec_NONE,

    kCodec_NUV_RTjpeg,
    kCodec_NUV_MPEG4,

    kCodec_MPEG1,
    kCodec_MPEG2,
    kCodec_H263,
    kCodec_MPEG4,
    kCodec_H264,
    kCodec_VC1,
    kCodec_WMV3,
    kCodec_VP8,
    kCodec_VP9,
    kCodec_HEVC,

    kCodec_NORMAL_END,
    
    kCodec_VDPAU_BEGIN = kCodec_NORMAL_END,

    kCodec_MPEG1_VDPAU,
    kCodec_MPEG2_VDPAU,
    kCodec_H263_VDPAU,
    kCodec_MPEG4_VDPAU,
    kCodec_H264_VDPAU,
    kCodec_VC1_VDPAU,
    kCodec_WMV3_VDPAU,
    kCodec_VP8_VDPAU,
    kCodec_VP9_VDPAU,
    kCodec_HEVC_VDPAU,

    kCodec_VDPAU_END,

    kCodec_VDPAU_DEC_BEGIN = kCodec_VDPAU_END,

    kCodec_MPEG1_VDPAU_DEC,
    kCodec_MPEG2_VDPAU_DEC,
    kCodec_H263_VDPAU_DEC,
    kCodec_MPEG4_VDPAU_DEC,
    kCodec_H264_VDPAU_DEC,
    kCodec_VC1_VDPAU_DEC,
    kCodec_WMV3_VDPAU_DEC,
    kCodec_VP8_VDPAU_DEC,
    kCodec_VP9_VDPAU_DEC,
    kCodec_HEVC_VDPAU_DEC,

    kCodec_VDPAU_DEC_END,

    kCodec_VAAPI_BEGIN = kCodec_VDPAU_DEC_END,

    kCodec_MPEG1_VAAPI,
    kCodec_MPEG2_VAAPI,
    kCodec_H263_VAAPI,
    kCodec_MPEG4_VAAPI,
    kCodec_H264_VAAPI,
    kCodec_VC1_VAAPI,
    kCodec_WMV3_VAAPI,
    kCodec_VP8_VAAPI,
    kCodec_VP9_VAAPI,
    kCodec_HEVC_VAAPI,

    kCodec_VAAPI_END,

    kCodec_VAAPI_DEC_BEGIN = kCodec_VAAPI_END,

    kCodec_MPEG1_VAAPI_DEC,
    kCodec_MPEG2_VAAPI_DEC,
    kCodec_H263_VAAPI_DEC,
    kCodec_MPEG4_VAAPI_DEC,
    kCodec_H264_VAAPI_DEC,
    kCodec_VC1_VAAPI_DEC,
    kCodec_WMV3_VAAPI_DEC,
    kCodec_VP8_VAAPI_DEC,
    kCodec_VP9_VAAPI_DEC,
    kCodec_HEVC_VAAPI_DEC,

    kCodec_VAAPI_DEC_END,

    kCodec_DXVA2_BEGIN = kCodec_VAAPI_DEC_END,

    kCodec_MPEG1_DXVA2,
    kCodec_MPEG2_DXVA2,
    kCodec_H263_DXVA2,
    kCodec_MPEG4_DXVA2,
    kCodec_H264_DXVA2,
    kCodec_VC1_DXVA2,
    kCodec_WMV3_DXVA2,
    kCodec_VP8_DXVA2,
    kCodec_VP9_DXVA2,
    kCodec_HEVC_DXVA2,

    kCodec_DXVA2_END,

    kCodec_MEDIACODEC_BEGIN = kCodec_DXVA2_END,

    kCodec_MPEG1_MEDIACODEC,
    kCodec_MPEG2_MEDIACODEC,
    kCodec_H263_MEDIACODEC,
    kCodec_MPEG4_MEDIACODEC,
    kCodec_H264_MEDIACODEC,
    kCodec_VC1_MEDIACODEC,
    kCodec_WMV3_MEDIACODEC,
    kCodec_VP8_MEDIACODEC,
    kCodec_VP9_MEDIACODEC,
    kCodec_HEVC_MEDIACODEC,

    kCodec_MEDIACODEC_END,

    kCodec_MEDIACODEC_DEC_BEGIN = kCodec_MEDIACODEC_END,

    kCodec_MPEG1_MEDIACODEC_DEC,
    kCodec_MPEG2_MEDIACODEC_DEC,
    kCodec_H263_MEDIACODEC_DEC,
    kCodec_MPEG4_MEDIACODEC_DEC,
    kCodec_H264_MEDIACODEC_DEC,
    kCodec_VC1_MEDIACODEC_DEC,
    kCodec_WMV3_MEDIACODEC_DEC,
    kCodec_VP8_MEDIACODEC_DEC,
    kCodec_VP9_MEDIACODEC_DEC,
    kCodec_HEVC_MEDIACODEC_DEC,

    kCodec_MEDIACODEC_DEC_END,

    kCodec_NVDEC_BEGIN = kCodec_MEDIACODEC_DEC_END,

    kCodec_MPEG1_NVDEC,
    kCodec_MPEG2_NVDEC,
    kCodec_H263_NVDEC,
    kCodec_MPEG4_NVDEC,
    kCodec_H264_NVDEC,
    kCodec_VC1_NVDEC,
    kCodec_WMV3_NVDEC,
    kCodec_VP8_NVDEC,
    kCodec_VP9_NVDEC,
    kCodec_HEVC_NVDEC,

    kCodec_NVDEC_END,

    kCodec_NVDEC_DEC_BEGIN = kCodec_NVDEC_END,

    kCodec_MPEG1_NVDEC_DEC,
    kCodec_MPEG2_NVDEC_DEC,
    kCodec_H263_NVDEC_DEC,
    kCodec_MPEG4_NVDEC_DEC,
    kCodec_H264_NVDEC_DEC,
    kCodec_VC1_NVDEC_DEC,
    kCodec_WMV3_NVDEC_DEC,
    kCodec_VP8_NVDEC_DEC,
    kCodec_VP9_NVDEC_DEC,
    kCodec_HEVC_NVDEC_DEC,

    kCodec_NVDEC_DEC_END,

    kCodec_VTB_BEGIN = kCodec_NVDEC_DEC_END,

    kCodec_MPEG1_VTB,
    kCodec_MPEG2_VTB,
    kCodec_H263_VTB,
    kCodec_MPEG4_VTB,
    kCodec_H264_VTB,
    kCodec_VC1_VTB,
    kCodec_WMV3_VTB,
    kCodec_VP8_VTB,
    kCodec_VP9_VTB,
    kCodec_HEVC_VTB,

    kCodec_VTB_END,

    kCodec_VTB_DEC_BEGIN = kCodec_VTB_END,

    kCodec_MPEG1_VTB_DEC,
    kCodec_MPEG2_VTB_DEC,
    kCodec_H263_VTB_DEC,
    kCodec_MPEG4_VTB_DEC,
    kCodec_H264_VTB_DEC,
    kCodec_VC1_VTB_DEC,
    kCodec_WMV3_VTB_DEC,
    kCodec_VP8_VTB_DEC,
    kCodec_VP9_VTB_DEC,
    kCodec_HEVC_VTB_DEC,

    kCodec_VTB_DEC_END,

    kCodec_OMXEGL_BEGIN = kCodec_VTB_DEC_END,
    kCodec_MPEG1_OMXEGL,
    kCodec_MPEG2_OMXEGL,
    kCodec_H263_OMXEGL,
    kCodec_MPEG4_OMXEGL,
    kCodec_H264_OMXEGL,
    kCodec_VC1_OMXEGL,
    kCodec_WMV3_OMXEGL,
    kCodec_VP8_OMXEGL,
    kCodec_VP9_OMXEGL,
    kCodec_HEVC_OMXEGL,

    kCodec_OMXEGL_END
} MythCodecID;

// MythCodecID convenience functions
#define codec_is_std(id)      (id < kCodec_NORMAL_END)
#define codec_is_std_mpeg(id) (id == kCodec_MPEG1 || id == kCodec_MPEG2)

#define codec_is_vdpau(id)    ((id > kCodec_VDPAU_BEGIN) && \
                               (id < kCodec_VDPAU_END))
#define codec_is_vdpau_hw(id) ((codec_is_vdpau(id) && \
                                (id != kCodec_H263_VDPAU) && \
                                (id != kCodec_VP8_VDPAU)))
#define codec_is_vdpau_dec(id)((id > kCodec_VDPAU_DEC_BEGIN) && \
                               (id < kCodec_VDPAU_DEC_END))

#define codec_is_vaapi(id)    ((id > kCodec_VAAPI_BEGIN) && \
                               (id < kCodec_VAAPI_END))
#define codec_is_vaapi_hw(id) (codec_is_vaapi(id) && \
                               (id != kCodec_VP8_VAAPI))
#define codec_is_vaapi_dec(id)((id > kCodec_VAAPI_DEC_BEGIN) && \
                               (id < kCodec_VAAPI_DEC_END))

#define codec_is_dxva2(id)    ((id > kCodec_DXVA2_BEGIN) && \
                               (id < kCodec_DXVA2_END))
#define codec_is_dxva2_hw(id) (codec_is_dxva2(id) && \
                               ((id == kCodec_H264_DXVA2)  || \
                                (id == kCodec_MPEG2_DXVA2) || \
                                (id == kCodec_VC1_DXVA2)))

#define codec_is_mediacodec(id)((id > kCodec_MEDIACODEC_BEGIN) && \
                               (id < kCodec_MEDIACODEC_END))
#define codec_is_mediacodec_dec(id) ((id > kCodec_MEDIACODEC_DEC_BEGIN) && \
                               (id < kCodec_MEDIACODEC_DEC_END))

#define codec_is_nvdec(id)    ((id > kCodec_NVDEC_BEGIN) && \
                               (id < kCodec_NVDEC_END))
#define codec_is_nvdec_dec(id)((id > kCodec_NVDEC_DEC_BEGIN) && \
                               (id < kCodec_NVDEC_DEC_END))

#define codec_is_vtb(id)      ((id > kCodec_VTB_BEGIN) && \
                               (id < kCodec_VTB_END))
#define codec_is_vtb_dec(id)  ((id > kCodec_VTB_DEC_BEGIN) && \
                               (id < kCodec_VTB_DEC_END))

#define codec_is_omxegl(id)   ((id > kCodec_OMXEGL_BEGIN) && (id < kCodec_OMXEGL_END))

#define codec_sw_copy(id) (codec_is_std(id) || codec_is_mediacodec_dec(id) || \
                           codec_is_vaapi_dec(id) || codec_is_nvdec_dec(id) || \
                           codec_is_vtb_dec(id) || codec_is_vdpau_dec(id))

QString get_encoding_type(MythCodecID codecid);
QString get_decoder_name(MythCodecID codec_id);
QString toString(MythCodecID codecid);
int myth2av_codecid(MythCodecID codec_id, bool &vdpau);
inline int myth2av_codecid(MythCodecID codec_id)
{
    bool vdpau;
    return myth2av_codecid(codec_id, vdpau);
}

// AV codec id convenience functions
int mpeg_version(int codec_id);
#define CODEC_IS_H264(id)     (mpeg_version(id) == 5)
#define CODEC_IS_MPEG(id)     (mpeg_version(id) && mpeg_version(id) <= 2)
#define CODEC_IS_FFMPEG_MPEG(id) (CODEC_IS_MPEG(id))
#ifdef USING_VDPAU
#define CODEC_IS_VDPAU(codec) (codec && codec->capabilities & CODEC_CAP_HWACCEL_VDPAU)
#else
#define CODEC_IS_VDPAU(codec) (0)
#endif

#ifdef USING_VAAPI
#define CODEC_IS_VAAPI(codec, enc) (codec && IS_VAAPI_PIX_FMT(enc->pix_fmt))
#else
#define CODEC_IS_VAAPI(codec, enc) (0)
#endif

#ifdef USING_DXVA2
#define CODEC_IS_DXVA2(codec, enc) (codec && (enc->pix_fmt == AV_PIX_FMT_DXVA2_VLD))
#else
#define CODEC_IS_DXVA2(codec, enc) (0)
#endif

#ifdef USING_MEDIACODEC
#define CODEC_IS_MEDIACODEC(codec) (codec && (QString("mediacodec") == codec->wrapper_name))
#else
#define CODEC_IS_MEDIACODEC(codec) (0)
#endif

#endif // _MYTH_CODEC_ID_H_
