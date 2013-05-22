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
 * one_time_construction.cpp
 *
 * Copyright 2006 The Android Open Source Project
 *
 * This file contains C++ ABI support functions for one time
 * constructors as defined in the "Run-time ABI for the ARM Architecture"
 * section 4.4.2
 */

#include <stddef.h>
#include <sys/atomics.h>
#include <bionic_futex.h>
#include <bionic_atomic_inline.h>

extern "C" int __cxa_guard_acquire(int volatile * gv)
{
    // 0 -> 2, return 1
    // 2 -> 6, wait and return 0
    // 6 untouched, wait and return 0
    // 1 untouched, return 0
retry:
    if (__atomic_cmpxchg(0, 0x2, gv) == 0) {
        ANDROID_MEMBAR_FULL();
        return 1;
    }
    __atomic_cmpxchg(0x2, 0x6, gv); // Indicate there is a waiter
    __futex_wait(gv, 0x6, NULL);

    if(*gv != 1) // __cxa_guard_abort was called, let every thread try since there is no return code for this condition
        goto retry;

    ANDROID_MEMBAR_FULL();
    return 0;
}

extern "C" void __cxa_guard_release(int volatile * gv)
{
    // 2 -> 1
    // 6 -> 1, and wake
    ANDROID_MEMBAR_FULL();
    if (__atomic_cmpxchg(0x2, 0x1, gv) == 0) {
        return;
    }

    *gv = 0x1;
    __futex_wake(gv, 0x7fffffff);
}

extern "C" void __cxa_guard_abort(int volatile * gv)
{
    ANDROID_MEMBAR_FULL();
    *gv = 0;
    __futex_wake(gv, 0x7fffffff);
}
