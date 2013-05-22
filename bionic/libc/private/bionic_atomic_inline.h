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
/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BIONIC_ATOMIC_INLINE_H
#define BIONIC_ATOMIC_INLINE_H

/*
 * Inline declarations and macros for some special-purpose atomic
 * operations.  These are intended for rare circumstances where a
 * memory barrier needs to be issued inline rather than as a function
 * call.
 *
 * Most code should not use these.
 *
 * Anything that does include this file must set ANDROID_SMP to either
 * 0 or 1, indicating compilation for UP or SMP, respectively.
 *
 * Macros defined in this header:
 *
 * void ANDROID_MEMBAR_FULL(void)
 *   Full memory barrier.  Provides a compiler reordering barrier, and
 *   on SMP systems emits an appropriate instruction.
 */

#if !defined(ANDROID_SMP)
# error "Must define ANDROID_SMP before including atomic-inline.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Define the full memory barrier for an SMP system.  This is
 * platform-specific.
 */

#ifdef __arm__
#include <machine/cpu-features.h>

/*
 * For ARMv6K we need to issue a specific MCR instead of the DMB, since
 * that wasn't added until v7.  For anything older, SMP isn't relevant.
 * Since we don't have an ARMv6K to test with, we're not going to deal
 * with that now.
 *
 * The DMB instruction is found in the ARM and Thumb2 instruction sets.
 * This will fail on plain 16-bit Thumb.
 */
#if defined(__ARM_HAVE_DMB)
# define _ANDROID_MEMBAR_FULL_SMP() \
    do { __asm__ __volatile__ ("dmb" ::: "memory"); } while (0)
#else
# define _ANDROID_MEMBAR_FULL_SMP()  ARM_SMP_defined_but_no_DMB()
#endif

#elif defined(__i386__) || defined(__x86_64__)
/*
 * For recent x86, we can use the SSE2 mfence instruction.
 */
# define _ANDROID_MEMBAR_FULL_SMP() \
    do { __asm__ __volatile__ ("mfence" ::: "memory"); } while (0)

#else
/*
 * Implementation not defined for this platform.  Hopefully we're building
 * in uniprocessor mode.
 */
# define _ANDROID_MEMBAR_FULL_SMP()  SMP_barrier_not_defined_for_platform()
#endif


/*
 * Full barrier.  On uniprocessors this is just a compiler reorder barrier,
 * which ensures that the statements appearing above the barrier in the C/C++
 * code will be issued after the statements appearing below the barrier.
 *
 * For SMP this also includes a memory barrier instruction.  On an ARM
 * CPU this means that the current core will flush pending writes, wait
 * for pending reads to complete, and discard any cached reads that could
 * be stale.  Other CPUs may do less, but the end result is equivalent.
 */
#if ANDROID_SMP != 0
# define ANDROID_MEMBAR_FULL() _ANDROID_MEMBAR_FULL_SMP()
#else
# define ANDROID_MEMBAR_FULL() \
    do { __asm__ __volatile__ ("" ::: "memory"); } while (0)
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // BIONIC_ATOMIC_INLINE_H
