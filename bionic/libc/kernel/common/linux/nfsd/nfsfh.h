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

/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_NFSD_FH_H
#define _LINUX_NFSD_FH_H

#include <asm/types.h>
#include <linux/nfsd/const.h>
#include <linux/nfsd/debug.h>

struct nfs_fhbase_old {
 __u32 fb_dcookie;
 __u32 fb_ino;
 __u32 fb_dirino;
 __u32 fb_dev;
 __u32 fb_xdev;
 __u32 fb_xino;
 __u32 fb_generation;
};

struct nfs_fhbase_new {
 __u8 fb_version;
 __u8 fb_auth_type;
 __u8 fb_fsid_type;
 __u8 fb_fileid_type;
 __u32 fb_auth[1];

};

struct knfsd_fh {
 unsigned int fh_size;
 union {
 struct nfs_fhbase_old fh_old;
 __u32 fh_pad[NFS4_FHSIZE/4];
 struct nfs_fhbase_new fh_new;
 } fh_base;
};

#define ofh_dcookie fh_base.fh_old.fb_dcookie
#define ofh_ino fh_base.fh_old.fb_ino
#define ofh_dirino fh_base.fh_old.fb_dirino
#define ofh_dev fh_base.fh_old.fb_dev
#define ofh_xdev fh_base.fh_old.fb_xdev
#define ofh_xino fh_base.fh_old.fb_xino
#define ofh_generation fh_base.fh_old.fb_generation

#define fh_version fh_base.fh_new.fb_version
#define fh_fsid_type fh_base.fh_new.fb_fsid_type
#define fh_auth_type fh_base.fh_new.fb_auth_type
#define fh_fileid_type fh_base.fh_new.fb_fileid_type
#define fh_auth fh_base.fh_new.fb_auth
#define fh_fsid fh_base.fh_new.fb_auth

#endif
