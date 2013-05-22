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
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <sys/linux-syscalls.h>
#include <machine/cpu-features.h>

.global __atomic_cmpxchg
.type __atomic_cmpxchg, %function
.global __atomic_swap
.type __atomic_swap, %function
.global __atomic_dec
.type __atomic_dec, %function
.global __atomic_inc
.type __atomic_inc, %function

#define FUTEX_WAIT 0
#define FUTEX_WAKE 1

#if defined(__ARM_HAVE_LDREX_STREX)
/*
 * ===========================================================================
 *      ARMv6+ implementation
 * ===========================================================================
 */

/* r0(addr) -> r0(old) */
__atomic_dec:
    .fnstart
    mov     r1, r0                      @ copy addr so we don't clobber it
1:  ldrex   r0, [r1]                    @ load current value into r0
    sub     r2, r0, #1                  @ generate new value into r2
    strex   r3, r2, [r1]                @ try to store new value; result in r3
    cmp     r3, #0                      @ success?
    bxeq    lr                          @ yes, return
    b       1b                          @ no, retry
    .fnend

/* r0(addr) -> r0(old) */
__atomic_inc:
    .fnstart
    mov     r1, r0
1:  ldrex   r0, [r1]
    add     r2, r0, #1
    strex   r3, r2, [r1]
    cmp     r3, #0
    bxeq    lr
    b       1b
    .fnend

/* r0(old) r1(new) r2(addr) -> r0(zero_if_succeeded) */
__atomic_cmpxchg:
    .fnstart
1:  mov     ip, #2                      @ ip=2 means "new != old"
    ldrex   r3, [r2]                    @ load current value into r3
    teq     r0, r3                      @ new == old?
    strexeq ip, r1, [r2]                @ yes, try store, set ip to 0 or 1
    teq     ip, #1                      @ strex failure?
    beq     1b                          @ yes, retry
    mov     r0, ip                      @ return 0 on success, 2 on failure
    bx      lr
    .fnend

/* r0(new) r1(addr) -> r0(old) */
__atomic_swap:
    .fnstart
1:  ldrex   r2, [r1]
    strex   r3, r0, [r1]
    teq     r3, #0
    bne     1b
    mov     r0, r2
    bx      lr
    .fnend

#else /*not defined __ARM_HAVE_LDREX_STREX*/
/*
 * ===========================================================================
 *      Pre-ARMv6 implementation
 * ===========================================================================
 */

    /* int __kernel_cmpxchg(int oldval, int newval, int* ptr) */
    .equ    kernel_cmpxchg, 0xFFFF0FC0
    .equ    kernel_atomic_base, 0xFFFF0FFF

/* r0(addr) -> r0(old) */
__atomic_dec:
    .fnstart
    .save {r4, lr}
    stmdb   sp!, {r4, lr}
    mov     r2, r0
1: @ atomic_dec
    ldr     r0, [r2]
    mov     r3, #kernel_atomic_base
    add     lr, pc, #4
    sub     r1, r0, #1
    add     pc, r3, #(kernel_cmpxchg - kernel_atomic_base)
    bcc     1b
    add     r0, r1, #1
    ldmia   sp!, {r4, lr}
    bx      lr
    .fnend

/* r0(addr) -> r0(old) */
__atomic_inc:
    .fnstart
    .save {r4, lr}
    stmdb   sp!, {r4, lr}
    mov     r2, r0
1: @ atomic_inc
    ldr     r0, [r2]
    mov     r3, #kernel_atomic_base
    add     lr, pc, #4
    add     r1, r0, #1
    add     pc, r3, #(kernel_cmpxchg - kernel_atomic_base)
    bcc     1b
    sub     r0, r1, #1
    ldmia   sp!, {r4, lr}
    bx      lr
    .fnend

/* r0(old) r1(new) r2(addr) -> r0(zero_if_succeeded) */
__atomic_cmpxchg:
    .fnstart
    .save {r4, lr}
    stmdb   sp!, {r4, lr}
    mov     r4, r0          /* r4 = save oldvalue */
1: @ atomic_cmpxchg
    mov     r3, #kernel_atomic_base
    add     lr, pc, #4
    mov     r0, r4          /* r0 = oldvalue */
    add     pc, r3, #(kernel_cmpxchg - kernel_atomic_base)
    bcs     2f              /* swap was made. we're good, return. */
    ldr     r3, [r2]        /* swap not made, see if it's because *ptr!=oldvalue */
    cmp     r3, r4
    beq     1b
2: @ atomic_cmpxchg
    ldmia   sp!, {r4, lr}
    bx      lr
    .fnend

/* r0(new) r1(addr) -> r0(old) */
__atomic_swap:
    .fnstart
    swp     r0, r0, [r1]
    bx      lr
    .fnend

#endif /*not defined __ARM_HAVE_LDREX_STREX*/


/* __futex_wait(*ftx, val, *timespec) */
/* __futex_wake(*ftx, counter) */
/* __futex_syscall3(*ftx, op, val) */
/* __futex_syscall4(*ftx, op, val, *timespec) */

.global __futex_wait
.type __futex_wait, %function

.global __futex_wake
.type __futex_wake, %function

.global __futex_syscall3
.type __futex_syscall3, %function

.global __futex_syscall4
.type __futex_syscall4, %function

#if __ARM_EABI__

__futex_syscall3:
    .fnstart
    stmdb   sp!, {r4, r7}
    .save   {r4, r7}
    ldr     r7, =__NR_futex
    swi     #0
    ldmia   sp!, {r4, r7}
    bx      lr
    .fnend

__futex_wait:
    .fnstart
    stmdb   sp!, {r4, r7}
    .save   {r4, r7}
    mov     r3, r2
    mov     r2, r1
    mov     r1, #FUTEX_WAIT
    ldr     r7, =__NR_futex
    swi     #0
    ldmia   sp!, {r4, r7}
    bx      lr
    .fnend

__futex_wake:
    .fnstart
    .save   {r4, r7}
    stmdb   sp!, {r4, r7}
    mov     r2, r1
    mov     r1, #FUTEX_WAKE
    ldr     r7, =__NR_futex
    swi     #0
    ldmia   sp!, {r4, r7}
    bx      lr
    .fnend

#else

__futex_syscall3:
    swi     #__NR_futex
    bx      lr

__futex_wait:
    mov     r3, r2
    mov     r2, r1
    mov     r1, #FUTEX_WAIT
    swi     #__NR_futex
    bx      lr

__futex_wake:
    mov     r2, r1
    mov     r1, #FUTEX_WAKE
    swi     #__NR_futex
    bx      lr

#endif

__futex_syscall4:
    b __futex_syscall3
