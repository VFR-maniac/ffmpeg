/*
 * Copyright (c) 2013 Guillaume Martres <smarter@ubuntu.com>
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <aom/aom_image.h>

#include "libaom.h"

enum AVPixelFormat ff_aom_imgfmt_to_pixfmt(aom_img_fmt_t img)
{
    switch (img) {
    case AOM_IMG_FMT_RGB24:     return AV_PIX_FMT_RGB24;
    case AOM_IMG_FMT_RGB565:    return AV_PIX_FMT_RGB565BE;
    case AOM_IMG_FMT_RGB555:    return AV_PIX_FMT_RGB555BE;
    case AOM_IMG_FMT_UYVY:      return AV_PIX_FMT_UYVY422;
    case AOM_IMG_FMT_YUY2:      return AV_PIX_FMT_YUYV422;
    case AOM_IMG_FMT_YVYU:      return AV_PIX_FMT_YVYU422;
    case AOM_IMG_FMT_BGR24:     return AV_PIX_FMT_BGR24;
    case AOM_IMG_FMT_ARGB:      return AV_PIX_FMT_ARGB;
    case AOM_IMG_FMT_ARGB_LE:   return AV_PIX_FMT_BGRA;
    case AOM_IMG_FMT_RGB565_LE: return AV_PIX_FMT_RGB565LE;
    case AOM_IMG_FMT_RGB555_LE: return AV_PIX_FMT_RGB555LE;
    case AOM_IMG_FMT_I420:      return AV_PIX_FMT_YUV420P;
    case AOM_IMG_FMT_I422:      return AV_PIX_FMT_YUV422P;
    case AOM_IMG_FMT_I444:      return AV_PIX_FMT_YUV444P;
    case AOM_IMG_FMT_444A:      return AV_PIX_FMT_YUVA444P;
#if AOM_IMAGE_ABI_VERSION >= 3
    case AOM_IMG_FMT_I440:      return AV_PIX_FMT_YUV440P;
    case AOM_IMG_FMT_I42016:    return AV_PIX_FMT_YUV420P16BE;
    case AOM_IMG_FMT_I42216:    return AV_PIX_FMT_YUV422P16BE;
    case AOM_IMG_FMT_I44416:    return AV_PIX_FMT_YUV444P16BE;
#endif
    default:                    return AV_PIX_FMT_NONE;
    }
}

aom_img_fmt_t ff_aom_pixfmt_to_imgfmt(enum AVPixelFormat pix)
{
    switch (pix) {
    case AV_PIX_FMT_RGB24:        return AOM_IMG_FMT_RGB24;
    case AV_PIX_FMT_RGB565BE:     return AOM_IMG_FMT_RGB565;
    case AV_PIX_FMT_RGB555BE:     return AOM_IMG_FMT_RGB555;
    case AV_PIX_FMT_UYVY422:      return AOM_IMG_FMT_UYVY;
    case AV_PIX_FMT_YUYV422:      return AOM_IMG_FMT_YUY2;
    case AV_PIX_FMT_YVYU422:      return AOM_IMG_FMT_YVYU;
    case AV_PIX_FMT_BGR24:        return AOM_IMG_FMT_BGR24;
    case AV_PIX_FMT_ARGB:         return AOM_IMG_FMT_ARGB;
    case AV_PIX_FMT_BGRA:         return AOM_IMG_FMT_ARGB_LE;
    case AV_PIX_FMT_RGB565LE:     return AOM_IMG_FMT_RGB565_LE;
    case AV_PIX_FMT_RGB555LE:     return AOM_IMG_FMT_RGB555_LE;
    case AV_PIX_FMT_YUV420P:      return AOM_IMG_FMT_I420;
    case AV_PIX_FMT_YUV422P:      return AOM_IMG_FMT_I422;
    case AV_PIX_FMT_YUV444P:      return AOM_IMG_FMT_I444;
    case AV_PIX_FMT_YUVA444P:     return AOM_IMG_FMT_444A;
#if AOM_IMAGE_ABI_VERSION >= 3
    case AV_PIX_FMT_YUV440P:      return AOM_IMG_FMT_I440;
    case AV_PIX_FMT_YUV420P16BE:  return AOM_IMG_FMT_I42016;
    case AV_PIX_FMT_YUV422P16BE:  return AOM_IMG_FMT_I42216;
    case AV_PIX_FMT_YUV444P16BE:  return AOM_IMG_FMT_I44416;
#endif
    default:                      return AOM_IMG_FMT_NONE;
    }
}
