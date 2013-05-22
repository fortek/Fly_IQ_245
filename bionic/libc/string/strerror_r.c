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
/* $OpenBSD: strerror_r.c,v 1.6 2005/08/08 08:05:37 espie Exp $ */
/* Public Domain <marc@snafu.org> */

#define sys_siglist	_sys_siglist

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <string.h>

typedef struct {
  int           code;
  const char*   msg;
} CodeString;

static const char*
__code_string_lookup( const CodeString*  strings,
                      int                code )
{
    int  nn = 0;

    for (;;)
    {
        if (strings[nn].code == 0)
            break;

        if (strings[nn].code == code)
            return strings[nn].msg;

        nn++;
    }
    return NULL;
}


static const CodeString  _sys_error_strings[] =
{
#define  __BIONIC_ERRDEF(x,y,z)  { y, z },
#include <sys/_errdefs.h>
    { 0, NULL }
};

static size_t
__digits10(unsigned int num)
{
	size_t i = 0;

	do {
		num /= 10;
		i++;
	} while (num != 0);

	return i;
}

static int
__itoa(int num, int sign, char *buffer, size_t start, size_t end)
{
	size_t pos;
	unsigned int a;
	int neg;

	if (sign && num < 0) {
		a = -num;
		neg = 1;
	}
	else {
		a = num;
		neg = 0;
	}

	pos = start + __digits10(a);
	if (neg)
	    pos++;

	if (pos < end)
		buffer[pos] = '\0';
	else
		return ERANGE;
	pos--;
	do {
		buffer[pos] = (a % 10) + '0';
		pos--;
		a /= 10;
	} while (a != 0);
	if (neg)
		buffer[pos] = '-';
	return 0;
}


int
strerror_r(int errnum, char *strerrbuf, size_t buflen)
{
    int          save_errno;
    int          len, ret = 0;
    const char*  msg;

    save_errno = errno;
    msg        = __code_string_lookup( _sys_error_strings, errnum );
    if (msg != NULL) {
        len = strlcpy(strerrbuf, msg, buflen);
        if ((size_t)len >= buflen)
            ret = ERANGE;
    } else {
        len = strlcpy(strerrbuf, "Unknown error: ", buflen);
        if ((size_t)len >= buflen)
            ret = ERANGE;
        else {
            int  ret = __itoa(errnum, 1, strerrbuf, len, buflen);

            if (ret == 0)
                ret = EINVAL;
        }
    }
    return ret;
}

#if 0
static const CodeString  _sys_signal_strings[] =
{
#define  SIGDEF(x,y,z)  { y, z },
#include <sys/_sigdefs.h>
};


static int
__num2string(int num, int sign, int setid, char *buf, size_t buflen,
    char * list[], size_t max, const char *def)
{
	int ret = 0;
	size_t len;

	if (0 <= num && num < max) {
		len = strlcpy(buf, def, buflen);
		if (len >= buflen)
			ret = ERANGE;
	} else {
		len = strlcpy(buf, def, buflen);
		if (len >= buflen)
			ret = ERANGE;
		else {
			ret = __itoa(num, sign, buf, len, buflen);
			if (ret == 0)
				ret = EINVAL;
		}
	}

	return ret;
}



#define USIGPREFIX "Unknown signal: "

char *
__strsignal(int num, char *buf)
{
	__num2string(num, 0, 2, buf, NL_TEXTMAX, (char **)sys_siglist, NSIG,
	    USIGPREFIX);
	return buf;
}
#endif
