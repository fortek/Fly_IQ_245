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
/*	$NetBSD: ffs.S,v 1.5 2003/04/05 23:08:52 bjh21 Exp $	*/
/*
 * Copyright (c) 2001 Christopher Gilbert
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the company nor the name of the author may be used to
 *    endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <machine/asm.h>

/*
 * ffs - find first set bit, this algorithm isolates the first set
 * bit, then multiplies the number by 0x0450fbaf which leaves the top
 * 6 bits as an index into the table.  This algorithm should be a win
 * over the checking each bit in turn as per the C compiled version.
 *
 * under ARMv5 there's an instruction called CLZ (count leading Zero's) that
 * could be used
 *
 * This is the ffs algorithm devised by d.seal and posted to comp.sys.arm on
 * 16 Feb 1994.
 */

ENTRY(ffs)
	/* Standard trick to isolate bottom bit in r0 or 0 if r0 = 0 on entry */
 	rsb     r1, r0, #0
 	ands    r0, r0, r1
#ifndef __ARM_ARCH_5__
	/*
	 * now r0 has at most one set bit, call this X
	 * if X = 0, all further instructions are skipped
	 */
	adrne   r2, .L_ffs_table
	orrne   r0, r0, r0, lsl #4  /* r0 = X * 0x11 */ 
	orrne   r0, r0, r0, lsl #6  /* r0 = X * 0x451 */
	rsbne   r0, r0, r0, lsl #16 /* r0 = X * 0x0450fbaf */
              
	/* now lookup in table indexed on top 6 bits of r0 */
	ldrneb  r0, [ r2, r0, lsr #26 ]

	bx		lr

.text;
.type .L_ffs_table, _ASM_TYPE_OBJECT;
.L_ffs_table:
/*               0   1   2   3   4   5   6   7           */
	.byte	 0,  1,  2, 13,  3,  7,  0, 14  /*  0- 7 */
	.byte	 4,  0,  8,  0,  0,  0,  0, 15  /*  8-15 */
	.byte	11,  5,  0,  0,  9,  0,  0, 26  /* 16-23 */
	.byte	 0,  0,  0,  0,  0, 22, 28, 16  /* 24-31 */
	.byte	32, 12,  6,  0,  0,  0,  0,  0	/* 32-39 */
	.byte	10,  0,  0, 25,  0,  0, 21, 27  /* 40-47 */
	.byte	31,  0,  0,  0,  0, 24,  0, 20  /* 48-55 */
	.byte   30,  0, 23, 19, 29, 18, 17,  0  /* 56-63 */
#else
	clzne	r0, r0
	rsbne	r0, r0, #32
	bx		lr
#endif

