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
/* s_cosf.c -- float version of s_cos.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 * Optimized by Bruce D. Evans.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#ifndef lint
static char rcsid[] = "$FreeBSD: src/lib/msun/src/s_cosf.c,v 1.15 2005/11/30 06:47:18 bde Exp $";
#endif

#include "math.h"
#define	INLINE_KERNEL_COSDF
#define	INLINE_KERNEL_SINDF
#include "math_private.h"
#include "k_cosf.c"
#include "k_sinf.c"

/* Small multiples of pi/2 rounded to double precision. */
static const double
c1pio2 = 1*M_PI_2,			/* 0x3FF921FB, 0x54442D18 */
c2pio2 = 2*M_PI_2,			/* 0x400921FB, 0x54442D18 */
c3pio2 = 3*M_PI_2,			/* 0x4012D97C, 0x7F3321D2 */
c4pio2 = 4*M_PI_2;			/* 0x401921FB, 0x54442D18 */

float
cosf(float x)
{
	float y[2];
	int32_t n, hx, ix;

	GET_FLOAT_WORD(hx,x);
	ix = hx & 0x7fffffff;

	if(ix <= 0x3f490fda) {		/* |x| ~<= pi/4 */
	    if(ix<0x39800000)		/* |x| < 2**-12 */
		if(((int)x)==0) return 1.0;	/* 1 with inexact if x != 0 */
	    return __kernel_cosdf(x);
	}
	if(ix<=0x407b53d1) {		/* |x| ~<= 5*pi/4 */
	    if(ix>0x4016cbe3)		/* |x|  ~> 3*pi/4 */
		return -__kernel_cosdf(x + (hx > 0 ? -c2pio2 : c2pio2));
	    else {
		if(hx>0)
		    return __kernel_sindf(c1pio2 - x);
		else
		    return __kernel_sindf(x + c1pio2);
	    }
	}
	if(ix<=0x40e231d5) {		/* |x| ~<= 9*pi/4 */
	    if(ix>0x40afeddf)		/* |x|  ~> 7*pi/4 */
		return __kernel_cosdf(x + (hx > 0 ? -c4pio2 : c4pio2));
	    else {
		if(hx>0)
		    return __kernel_sindf(x - c3pio2);
		else
		    return __kernel_sindf(-c3pio2 - x);
	    }
	}

    /* cos(Inf or NaN) is NaN */
	else if (ix>=0x7f800000) return x-x;

    /* general argument reduction needed */
	else {
	    n = __ieee754_rem_pio2f(x,y);
	    switch(n&3) {
		case 0: return  __kernel_cosdf((double)y[0]+y[1]);
		case 1: return  __kernel_sindf(-(double)y[0]-y[1]);
		case 2: return -__kernel_cosdf((double)y[0]+y[1]);
		default:
		        return  __kernel_sindf((double)y[0]+y[1]);
	    }
	}
}
