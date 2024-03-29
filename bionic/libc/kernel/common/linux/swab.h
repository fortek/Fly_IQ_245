/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_SWAB_H
#define _LINUX_SWAB_H

#include <linux/types.h>
#include <linux/compiler.h>
#include <asm/swab.h>

#define ___constant_swab16(x) ((__u16)(   (((__u16)(x) & (__u16)0x00ffU) << 8) |   (((__u16)(x) & (__u16)0xff00U) >> 8)))

#define ___constant_swab32(x) ((__u32)(   (((__u32)(x) & (__u32)0x000000ffUL) << 24) |   (((__u32)(x) & (__u32)0x0000ff00UL) << 8) |   (((__u32)(x) & (__u32)0x00ff0000UL) >> 8) |   (((__u32)(x) & (__u32)0xff000000UL) >> 24)))

#define ___constant_swab64(x) ((__u64)(   (((__u64)(x) & (__u64)0x00000000000000ffULL) << 56) |   (((__u64)(x) & (__u64)0x000000000000ff00ULL) << 40) |   (((__u64)(x) & (__u64)0x0000000000ff0000ULL) << 24) |   (((__u64)(x) & (__u64)0x00000000ff000000ULL) << 8) |   (((__u64)(x) & (__u64)0x000000ff00000000ULL) >> 8) |   (((__u64)(x) & (__u64)0x0000ff0000000000ULL) >> 24) |   (((__u64)(x) & (__u64)0x00ff000000000000ULL) >> 40) |   (((__u64)(x) & (__u64)0xff00000000000000ULL) >> 56)))

#define ___constant_swahw32(x) ((__u32)(   (((__u32)(x) & (__u32)0x0000ffffUL) << 16) |   (((__u32)(x) & (__u32)0xffff0000UL) >> 16)))

#define ___constant_swahb32(x) ((__u32)(   (((__u32)(x) & (__u32)0x00ff00ffUL) << 8) |   (((__u32)(x) & (__u32)0xff00ff00UL) >> 8)))

#ifdef __arch_swab16
#else
#endif
#ifdef __arch_swab32
#else
#endif
#ifdef __arch_swab64
#elif defined(__SWAB_64_THRU_32__)
#else
#endif
#ifdef __arch_swahw32
#else
#endif
#ifdef __arch_swahb32
#else
#endif
#define __swab16(x)   (__builtin_constant_p((__u16)(x)) ?   ___constant_swab16(x) :   __fswab16(x))
#define __swab32(x)   (__builtin_constant_p((__u32)(x)) ?   ___constant_swab32(x) :   __fswab32(x))
#define __swab64(x)   (__builtin_constant_p((__u64)(x)) ?   ___constant_swab64(x) :   __fswab64(x))
#define __swahw32(x)   (__builtin_constant_p((__u32)(x)) ?   ___constant_swahw32(x) :   __fswahw32(x))
#define __swahb32(x)   (__builtin_constant_p((__u32)(x)) ?   ___constant_swahb32(x) :   __fswahb32(x))
#ifdef __arch_swab16p
#else
#endif
#ifdef __arch_swab32p
#else
#endif
#ifdef __arch_swab64p
#else
#endif
#ifdef __arch_swahw32p
#else
#endif
#ifdef __arch_swahb32p
#else
#endif
#ifdef __arch_swab16s
#else
#endif
#ifdef __arch_swab32s
#else
#endif
#ifdef __arch_swab64s
#else
#endif
#ifdef __arch_swahw32s
#else
#endif
#ifdef __arch_swahb32s
#else
#endif
#endif
