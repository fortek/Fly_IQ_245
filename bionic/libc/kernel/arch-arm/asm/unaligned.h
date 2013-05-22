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
#ifndef __ASM_ARM_UNALIGNED_H
#define __ASM_ARM_UNALIGNED_H

#include <asm/types.h>

#define __get_unaligned_2_le(__p)   (__p[0] | __p[1] << 8)

#define __get_unaligned_2_be(__p)   (__p[0] << 8 | __p[1])

#define __get_unaligned_4_le(__p)   (__p[0] | __p[1] << 8 | __p[2] << 16 | __p[3] << 24)

#define __get_unaligned_4_be(__p)   (__p[0] << 24 | __p[1] << 16 | __p[2] << 8 | __p[3])

#define __get_unaligned_le(ptr)   ({   __typeof__(*(ptr)) __v;   __u8 *__p = (__u8 *)(ptr);   switch (sizeof(*(ptr))) {   case 1: __v = *(ptr); break;   case 2: __v = __get_unaligned_2_le(__p); break;   case 4: __v = __get_unaligned_4_le(__p); break;   case 8: {   unsigned int __v1, __v2;   __v2 = __get_unaligned_4_le((__p+4));   __v1 = __get_unaligned_4_le(__p);   __v = ((unsigned long long)__v2 << 32 | __v1);   }   break;   default: __v = __bug_unaligned_x(__p); break;   }   __v;   })

#define __get_unaligned_be(ptr)   ({   __typeof__(*(ptr)) __v;   __u8 *__p = (__u8 *)(ptr);   switch (sizeof(*(ptr))) {   case 1: __v = *(ptr); break;   case 2: __v = __get_unaligned_2_be(__p); break;   case 4: __v = __get_unaligned_4_be(__p); break;   case 8: {   unsigned int __v1, __v2;   __v2 = __get_unaligned_4_be(__p);   __v1 = __get_unaligned_4_be((__p+4));   __v = ((unsigned long long)__v2 << 32 | __v1);   }   break;   default: __v = __bug_unaligned_x(__p); break;   }   __v;   })

#define __put_unaligned_le(val,ptr)   ({   switch (sizeof(*(ptr))) {   case 1:   *(ptr) = (val);   break;   case 2: __put_unaligned_2_le((val),(__u8 *)(ptr));   break;   case 4: __put_unaligned_4_le((val),(__u8 *)(ptr));   break;   case 8: __put_unaligned_8_le((val),(__u8 *)(ptr));   break;   default: __bug_unaligned_x(ptr);   break;   }   (void) 0;   })
#define __put_unaligned_be(val,ptr)   ({   switch (sizeof(*(ptr))) {   case 1:   *(ptr) = (val);   break;   case 2: __put_unaligned_2_be((val),(__u8 *)(ptr));   break;   case 4: __put_unaligned_4_be((val),(__u8 *)(ptr));   break;   case 8: __put_unaligned_8_be((val),(__u8 *)(ptr));   break;   default: __bug_unaligned_x(ptr);   break;   }   (void) 0;   })
#ifndef __ARMEB__
#define get_unaligned __get_unaligned_le
#define put_unaligned __put_unaligned_le
#else
#define get_unaligned __get_unaligned_be
#define put_unaligned __put_unaligned_be
#endif
#endif
