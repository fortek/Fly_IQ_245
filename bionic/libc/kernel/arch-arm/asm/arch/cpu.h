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
#ifndef __ASM_ARCH_OMAP_CPU_H
#define __ASM_ARCH_OMAP_CPU_H

#define omap2_cpu_rev() ((system_rev >> 8) & 0x0f)

#undef MULTI_OMAP1
#undef MULTI_OMAP2
#undef OMAP_NAME

#define GET_OMAP_CLASS (system_rev & 0xff)

#define IS_OMAP_CLASS(class, id)  static inline int is_omap ##class (void)  {   return (GET_OMAP_CLASS == (id)) ? 1 : 0;  }

#define GET_OMAP_SUBCLASS ((system_rev >> 20) & 0x0fff)

#define IS_OMAP_SUBCLASS(subclass, id)  static inline int is_omap ##subclass (void)  {   return (GET_OMAP_SUBCLASS == (id)) ? 1 : 0;  }

#define cpu_is_omap7xx() 0
#define cpu_is_omap15xx() 0
#define cpu_is_omap16xx() 0
#define cpu_is_omap24xx() 0
#define cpu_is_omap242x() 0
#define cpu_is_omap243x() 0
#ifdef MULTI_OMAP1
#else
#endif
#define GET_OMAP_TYPE ((system_rev >> 16) & 0xffff)
#define IS_OMAP_TYPE(type, id)  static inline int is_omap ##type (void)  {   return (GET_OMAP_TYPE == (id)) ? 1 : 0;  }
#define cpu_is_omap310() 0
#define cpu_is_omap730() 0
#define cpu_is_omap1510() 0
#define cpu_is_omap1610() 0
#define cpu_is_omap5912() 0
#define cpu_is_omap1611() 0
#define cpu_is_omap1621() 0
#define cpu_is_omap1710() 0
#define cpu_is_omap2420() 0
#define cpu_is_omap2422() 0
#define cpu_is_omap2423() 0
#define cpu_is_omap2430() 0
#ifdef MULTI_OMAP1
#else
#endif
#define cpu_class_is_omap1() (cpu_is_omap730() || cpu_is_omap15xx() ||   cpu_is_omap16xx())
#define cpu_class_is_omap2() cpu_is_omap24xx()
#endif
