/* Copyright Statement:
 * 
 * This software/firmware and related documentation ("MediaTek Software") are 
 * protected under relevant copyright laws. The information contained herein is 
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without 
 * the prior written permission of MediaTek inc. and/or its licensors, any 
 * reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly 
 * prohibited.  
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") 
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON 
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER 
 * DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF 
 * ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE 
 * MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR 
 * ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT 
 * IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER 
 * LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE 
 * RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S 
 * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. 
 * RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE 
 * LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, 
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
#ifndef __ASM_CMPXCHG_H
#define __ASM_CMPXCHG_H

#include <linux/bitops.h>  

#define xchg(ptr,v) ((__typeof__(*(ptr)))__xchg((unsigned long)(v),(ptr),sizeof(*(ptr))))

struct __xchg_dummy { unsigned long a[100]; };
#define __xg(x) ((struct __xchg_dummy *)(x))

#define ll_low(x) *(((unsigned int*)&(x))+0)
#define ll_high(x) *(((unsigned int*)&(x))+1)
#define set_64bit(ptr,value)  (__builtin_constant_p(value) ?   __set_64bit_constant(ptr, value) :   __set_64bit_var(ptr, value) )
#define _set_64bit(ptr,value)  (__builtin_constant_p(value) ?   __set_64bit(ptr, (unsigned int)(value), (unsigned int)((value)>>32ULL) ) :   __set_64bit(ptr, ll_low(value), ll_high(value)) )

#define cmpxchg(ptr,o,n)  ({   __typeof__(*(ptr)) __ret;   if (likely(boot_cpu_data.x86 > 3))   __ret = __cmpxchg((ptr), (unsigned long)(o),   (unsigned long)(n), sizeof(*(ptr)));   else   __ret = cmpxchg_386((ptr), (unsigned long)(o),   (unsigned long)(n), sizeof(*(ptr)));   __ret;  })
#define cmpxchg_local(ptr,o,n)  ({   __typeof__(*(ptr)) __ret;   if (likely(boot_cpu_data.x86 > 3))   __ret = __cmpxchg_local((ptr), (unsigned long)(o),   (unsigned long)(n), sizeof(*(ptr)));   else   __ret = cmpxchg_386((ptr), (unsigned long)(o),   (unsigned long)(n), sizeof(*(ptr)));   __ret;  })
#define cmpxchg64(ptr,o,n)  ((__typeof__(*(ptr)))__cmpxchg64((ptr),(unsigned long long)(o),  (unsigned long long)(n)))
#define cmpxchg64_local(ptr,o,n)  ((__typeof__(*(ptr)))__cmpxchg64_local((ptr),(unsigned long long)(o),  (unsigned long long)(n)))
#endif
