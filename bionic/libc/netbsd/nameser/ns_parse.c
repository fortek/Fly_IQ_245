/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/*	$NetBSD: ns_parse.c,v 1.2 2004/05/20 20:35:05 christos Exp $	*/

/*
 * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")
 * Copyright (c) 1996,1999 by Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/cdefs.h>
#ifndef lint
#ifdef notdef
static const char rcsid[] = "Id: ns_parse.c,v 1.3.2.1.4.1 2004/03/09 08:33:44 marka Exp";
#else
__RCSID("$NetBSD: ns_parse.c,v 1.2 2004/05/20 20:35:05 christos Exp $");
#endif
#endif

/* Import. */

#include <sys/types.h>

#include <netinet/in.h>
#include "arpa_nameser.h"

#include <errno.h>
#ifdef ANDROID_CHANGES
#include "resolv_private.h"
#else
#include <resolv.h>
#endif
#include <string.h>

/* Forward. */

static void	setsection(ns_msg *msg, ns_sect sect);

/* Macros. */

#define RETERR(err) do { errno = (err); return (-1); } while (/*NOTREACHED*//*CONSTCOND*/0)

/* Public. */

/* These need to be in the same order as the nres.h:ns_flag enum. */
const struct _ns_flagdata _ns_flagdata[16] = {
	{ 0x8000, 15 },		/* qr. */
	{ 0x7800, 11 },		/* opcode. */
	{ 0x0400, 10 },		/* aa. */
	{ 0x0200, 9 },		/* tc. */
	{ 0x0100, 8 },		/* rd. */
	{ 0x0080, 7 },		/* ra. */
	{ 0x0040, 6 },		/* z. */
	{ 0x0020, 5 },		/* ad. */
	{ 0x0010, 4 },		/* cd. */
	{ 0x000f, 0 },		/* rcode. */
	{ 0x0000, 0 },		/* expansion (1/6). */
	{ 0x0000, 0 },		/* expansion (2/6). */
	{ 0x0000, 0 },		/* expansion (3/6). */
	{ 0x0000, 0 },		/* expansion (4/6). */
	{ 0x0000, 0 },		/* expansion (5/6). */
	{ 0x0000, 0 },		/* expansion (6/6). */
};

int ns_msg_getflag(ns_msg handle, int flag) {
	return((u_int32_t)((handle)._flags & _ns_flagdata[flag].mask) >> _ns_flagdata[flag].shift);
}

int
ns_skiprr(const u_char *ptr, const u_char *eom, ns_sect section, int count) {
	const u_char *optr = ptr;

	for (; count > 0; count--) {
		int b, rdlength;

		b = dn_skipname(ptr, eom);
		if (b < 0)
			RETERR(EMSGSIZE);
		ptr += b/*Name*/ + NS_INT16SZ/*Type*/ + NS_INT16SZ/*Class*/;
		if (section != ns_s_qd) {
			if (ptr + NS_INT32SZ + NS_INT16SZ > eom)
				RETERR(EMSGSIZE);
			ptr += NS_INT32SZ/*TTL*/;
			NS_GET16(rdlength, ptr);
			ptr += rdlength/*RData*/;
		}
	}
	if (ptr > eom)
		RETERR(EMSGSIZE);
	return (ptr - optr);
}

int
ns_initparse(const u_char *msg, int msglen, ns_msg *handle) {
	const u_char *eom = msg + msglen;
	int i;

	memset(handle, 0x5e, sizeof *handle);
	handle->_msg = msg;
	handle->_eom = eom;
	if (msg + NS_INT16SZ > eom)
		RETERR(EMSGSIZE);
	NS_GET16(handle->_id, msg);
	if (msg + NS_INT16SZ > eom)
		RETERR(EMSGSIZE);
	NS_GET16(handle->_flags, msg);
	for (i = 0; i < ns_s_max; i++) {
		if (msg + NS_INT16SZ > eom)
			RETERR(EMSGSIZE);
		NS_GET16(handle->_counts[i], msg);
	}
	for (i = 0; i < ns_s_max; i++)
		if (handle->_counts[i] == 0)
			handle->_sections[i] = NULL;
		else {
			int b = ns_skiprr(msg, eom, (ns_sect)i,
					  handle->_counts[i]);

			if (b < 0)
				return (-1);
			handle->_sections[i] = msg;
			msg += b;
		}
	if (msg != eom)
		RETERR(EMSGSIZE);
	setsection(handle, ns_s_max);
	return (0);
}

int
ns_parserr(ns_msg *handle, ns_sect section, int rrnum, ns_rr *rr) {
	int b;

	/* Make section right. */
	if ((unsigned)section >= (unsigned)ns_s_max)
		RETERR(ENODEV);
	if (section != handle->_sect)
		setsection(handle, section);

	/* Make rrnum right. */
	if (rrnum == -1)
		rrnum = handle->_rrnum;
	if (rrnum < 0 || rrnum >= handle->_counts[(int)section])
		RETERR(ENODEV);
	if (rrnum < handle->_rrnum)
		setsection(handle, section);
	if (rrnum > handle->_rrnum) {
		b = ns_skiprr(handle->_msg_ptr, handle->_eom, section,
			      rrnum - handle->_rrnum);

		if (b < 0)
			return (-1);
		handle->_msg_ptr += b;
		handle->_rrnum = rrnum;
	}

	/* Do the parse. */
	b = dn_expand(handle->_msg, handle->_eom,
		      handle->_msg_ptr, rr->name, NS_MAXDNAME);
	if (b < 0)
		return (-1);
	handle->_msg_ptr += b;
	if (handle->_msg_ptr + NS_INT16SZ + NS_INT16SZ > handle->_eom)
		RETERR(EMSGSIZE);
	NS_GET16(rr->type, handle->_msg_ptr);
	NS_GET16(rr->rr_class, handle->_msg_ptr);
	if (section == ns_s_qd) {
		rr->ttl = 0;
		rr->rdlength = 0;
		rr->rdata = NULL;
	} else {
		if (handle->_msg_ptr + NS_INT32SZ + NS_INT16SZ > handle->_eom)
			RETERR(EMSGSIZE);
		NS_GET32(rr->ttl, handle->_msg_ptr);
		NS_GET16(rr->rdlength, handle->_msg_ptr);
		if (handle->_msg_ptr + rr->rdlength > handle->_eom)
			RETERR(EMSGSIZE);
		rr->rdata = handle->_msg_ptr;
		handle->_msg_ptr += rr->rdlength;
	}
	if (++handle->_rrnum > handle->_counts[(int)section])
		setsection(handle, (ns_sect)((int)section + 1));

	/* All done. */
	return (0);
}

/* Private. */

static void
setsection(ns_msg *msg, ns_sect sect) {
	msg->_sect = sect;
	if (sect == ns_s_max) {
		msg->_rrnum = -1;
		msg->_msg_ptr = NULL;
	} else {
		msg->_rrnum = 0;
		msg->_msg_ptr = msg->_sections[(int)sect];
	}
}
