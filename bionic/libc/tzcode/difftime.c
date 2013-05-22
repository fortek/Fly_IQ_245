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
** This file is in the public domain, so clarified as of
** 1996-06-05 by Arthur David Olson.
*/

#ifndef lint
#ifndef NOID
static char elsieid[] = "@(#)difftime.c 8.1";
#endif /* !defined NOID */
#endif /* !defined lint */

/*LINTLIBRARY*/

#include "private.h"    /* for time_t, TYPE_INTEGRAL, and TYPE_SIGNED */

double
difftime(time1, time0)
const time_t    time1;
const time_t    time0;
{
    /*
    ** If (sizeof (double) > sizeof (time_t)) simply convert and subtract
    ** (assuming that the larger type has more precision).
    ** This is the common real-world case circa 2004.
    */
    if (sizeof (double) > sizeof (time_t))
        return (double) time1 - (double) time0;
    if (!TYPE_INTEGRAL(time_t)) {
        /*
        ** time_t is floating.
        */
        return time1 - time0;
    }
    if (!TYPE_SIGNED(time_t)) {
        /*
        ** time_t is integral and unsigned.
        ** The difference of two unsigned values can't overflow
        ** if the minuend is greater than or equal to the subtrahend.
        */
        if (time1 >= time0)
            return time1 - time0;
        else    return -((double) (time0 - time1));
    }
    /*
    ** time_t is integral and signed.
    ** Handle cases where both time1 and time0 have the same sign
    ** (meaning that their difference cannot overflow).
    */
    if ((time1 < 0) == (time0 < 0))
        return time1 - time0;
    /*
    ** time1 and time0 have opposite signs.
    ** Punt if unsigned long is too narrow.
    */
    if (sizeof (unsigned long) < sizeof (time_t))
        return (double) time1 - (double) time0;
    /*
    ** Stay calm...decent optimizers will eliminate the complexity below.
    */
    if (time1 >= 0 /* && time0 < 0 */)
        return (unsigned long) time1 +
            (unsigned long) (-(time0 + 1)) + 1;
    return -(double) ((unsigned long) time0 +
        (unsigned long) (-(time1 + 1)) + 1);
}
