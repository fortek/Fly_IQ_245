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
/*-
 * Copyright (c) 2004-2005 David Schultz <das@FreeBSD.ORG>
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
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: src/lib/msun/i387/fenv.h,v 1.4 2005/03/17 22:21:46 das Exp $
 */

#ifndef	_FENV_H_
#define	_FENV_H_

#include <sys/cdefs.h>
#include <sys/_types.h>

/*                   
 * To preserve binary compatibility with FreeBSD 5.3, we pack the
 * mxcsr into some reserved fields, rather than changing sizeof(fenv_t).
 */
typedef struct {
	__uint16_t	__control;
	__uint16_t      __mxcsr_hi;
	__uint16_t	__status;
	__uint16_t      __mxcsr_lo;
	__uint32_t	__tag;
	char		__other[16];
} fenv_t;

#define	__get_mxcsr(env)	(((env).__mxcsr_hi << 16) |	\
				 ((env).__mxcsr_lo))
#define	__set_mxcsr(env, x)	do {				\
	(env).__mxcsr_hi = (__uint32_t)(x) >> 16;		\
	(env).__mxcsr_lo = (__uint16_t)(x);			\
} while (0)

typedef	__uint16_t	fexcept_t;

/* Exception flags */
#define	FE_INVALID	0x01
#define	FE_DENORMAL	0x02
#define	FE_DIVBYZERO	0x04
#define	FE_OVERFLOW	0x08
#define	FE_UNDERFLOW	0x10
#define	FE_INEXACT	0x20
#define	FE_ALL_EXCEPT	(FE_DIVBYZERO | FE_DENORMAL | FE_INEXACT | \
			 FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW)

/* Rounding modes */
#define	FE_TONEAREST	0x0000
#define	FE_DOWNWARD	0x0400
#define	FE_UPWARD	0x0800
#define	FE_TOWARDZERO	0x0c00
#define	_ROUND_MASK	(FE_TONEAREST | FE_DOWNWARD | \
			 FE_UPWARD | FE_TOWARDZERO)

/*
 * As compared to the x87 control word, the SSE unit's control word
 * has the rounding control bits offset by 3 and the exception mask
 * bits offset by 7.
 */
#define	_SSE_ROUND_SHIFT	3
#define	_SSE_EMASK_SHIFT	7

/* After testing for SSE support once, we cache the result in __has_sse. */
enum __sse_support { __SSE_YES, __SSE_NO, __SSE_UNK };
extern enum __sse_support __has_sse;
int __test_sse(void);
#ifdef __SSE__
#define	__HAS_SSE()	1
#else
#define	__HAS_SSE()	(__has_sse == __SSE_YES ||			\
			 (__has_sse == __SSE_UNK && __test_sse()))
#endif

__BEGIN_DECLS

/* Default floating-point environment */
extern const fenv_t	__fe_dfl_env;
#define	FE_DFL_ENV	(&__fe_dfl_env)

#define	__fldcw(__cw)		__asm __volatile("fldcw %0" : : "m" (__cw))
#define	__fldenv(__env)		__asm __volatile("fldenv %0" : : "m" (__env))
#define	__fnclex()		__asm __volatile("fnclex")
#define	__fnstenv(__env)	__asm __volatile("fnstenv %0" : "=m" (*(__env)))
#define	__fnstcw(__cw)		__asm __volatile("fnstcw %0" : "=m" (*(__cw)))
#define	__fnstsw(__sw)		__asm __volatile("fnstsw %0" : "=am" (*(__sw)))
#define	__fwait()		__asm __volatile("fwait")
#define	__ldmxcsr(__csr)	__asm __volatile("ldmxcsr %0" : : "m" (__csr))
#define	__stmxcsr(__csr)	__asm __volatile("stmxcsr %0" : "=m" (*(__csr)))

static __inline int
feclearexcept(int __excepts)
{
	fenv_t __env;
	int __mxcsr;

	if (__excepts == FE_ALL_EXCEPT) {
		__fnclex();
	} else {
		__fnstenv(&__env);
		__env.__status &= ~__excepts;
		__fldenv(__env);
	}
	if (__HAS_SSE()) {
		__stmxcsr(&__mxcsr);
		__mxcsr &= ~__excepts;
		__ldmxcsr(__mxcsr);
	}
	return (0);
}

static __inline int
fegetexceptflag(fexcept_t *__flagp, int __excepts)
{
	int __mxcsr, __status;

	__fnstsw(&__status);
	if (__HAS_SSE())
		__stmxcsr(&__mxcsr);
	else
		__mxcsr = 0;
	*__flagp = (__mxcsr | __status) & __excepts;
	return (0);
}

int fesetexceptflag(const fexcept_t *__flagp, int __excepts);
int feraiseexcept(int __excepts);

static __inline int
fetestexcept(int __excepts)
{
	int __mxcsr, __status;

	__fnstsw(&__status);
	if (__HAS_SSE())
		__stmxcsr(&__mxcsr);
	else
		__mxcsr = 0;
	return ((__status | __mxcsr) & __excepts);
}

static __inline int
fegetround(void)
{
	int __control;

	/*
	 * We assume that the x87 and the SSE unit agree on the
	 * rounding mode.  Reading the control word on the x87 turns
	 * out to be about 5 times faster than reading it on the SSE
	 * unit on an Opteron 244.
	 */
	__fnstcw(&__control);
	return (__control & _ROUND_MASK);
}

static __inline int
fesetround(int __round)
{
	int __mxcsr, __control;

	if (__round & ~_ROUND_MASK)
		return (-1);

	__fnstcw(&__control);
	__control &= ~_ROUND_MASK;
	__control |= __round;
	__fldcw(__control);

	if (__HAS_SSE()) {
		__stmxcsr(&__mxcsr);
		__mxcsr &= ~(_ROUND_MASK << _SSE_ROUND_SHIFT);
		__mxcsr |= __round << _SSE_ROUND_SHIFT;
		__ldmxcsr(__mxcsr);
	}

	return (0);
}

int fegetenv(fenv_t *__envp);
int feholdexcept(fenv_t *__envp);

static __inline int
fesetenv(const fenv_t *__envp)
{
	fenv_t __env = *__envp;
	int __mxcsr;

	__mxcsr = __get_mxcsr(__env);
	__set_mxcsr(__env, 0xffffffff);
	__fldenv(__env);
	if (__HAS_SSE())
		__ldmxcsr(__mxcsr);
	return (0);
}

int feupdateenv(const fenv_t *__envp);

#if __BSD_VISIBLE

int feenableexcept(int __mask);
int fedisableexcept(int __mask);

static __inline int
fegetexcept(void)
{
	int __control;

	/*
	 * We assume that the masks for the x87 and the SSE unit are
	 * the same.
	 */
	__fnstcw(&__control);
	return (~__control & FE_ALL_EXCEPT);
}

#endif /* __BSD_VISIBLE */

__END_DECLS

#endif	/* !_FENV_H_ */
