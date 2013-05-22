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
/*	$OpenBSD: strcmp.S,v 1.3 2005/08/07 11:30:38 espie Exp $ */
/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Public domain.
 */

#include <machine/asm.h>

/*
 * NOTE: I've unrolled the loop eight times: large enough to make a
 * significant difference, and small enough not to totally trash the
 * cache.
 */

ENTRY(strcmp)
	movl	0x04(%esp),%eax
	movl	0x08(%esp),%edx
	jmp	L2			/* Jump into the loop! */

	.align	2,0x90
L1:	incl	%eax
	incl	%edx
L2:	movb	(%eax),%cl
	testb	%cl,%cl			/* null terminator??? */
	jz	L3
	cmpb	%cl,(%edx)		/* chars match??? */
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	jne	L3
	incl	%eax
	incl	%edx
	movb	(%eax),%cl
	testb	%cl,%cl
	jz	L3
	cmpb	%cl,(%edx)
	je	L1
	.align 2, 0x90
L3:	movzbl	(%eax),%eax		/* unsigned comparison */
	movzbl	(%edx),%edx
	subl	%edx,%eax
	ret
