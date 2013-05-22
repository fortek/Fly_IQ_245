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
#ifndef LINUX_NFSD_H
#define LINUX_NFSD_H

#include <linux/fs.h>
#include <linux/vfs.h>
#include <linux/nfs.h>

struct nfsd_fhandle {
 struct svc_fh fh;
};

struct nfsd_sattrargs {
 struct svc_fh fh;
 struct iattr attrs;
};

struct nfsd_diropargs {
 struct svc_fh fh;
 char * name;
 int len;
};

struct nfsd_readargs {
 struct svc_fh fh;
 __u32 offset;
 __u32 count;
 struct kvec vec[RPCSVC_MAXPAGES];
 int vlen;
};

struct nfsd_writeargs {
 svc_fh fh;
 __u32 offset;
 int len;
 struct kvec vec[RPCSVC_MAXPAGES];
 int vlen;
};

struct nfsd_createargs {
 struct svc_fh fh;
 char * name;
 int len;
 struct iattr attrs;
};

struct nfsd_renameargs {
 struct svc_fh ffh;
 char * fname;
 int flen;
 struct svc_fh tfh;
 char * tname;
 int tlen;
};

struct nfsd_readlinkargs {
 struct svc_fh fh;
 char * buffer;
};

struct nfsd_linkargs {
 struct svc_fh ffh;
 struct svc_fh tfh;
 char * tname;
 int tlen;
};

struct nfsd_symlinkargs {
 struct svc_fh ffh;
 char * fname;
 int flen;
 char * tname;
 int tlen;
 struct iattr attrs;
};

struct nfsd_readdirargs {
 struct svc_fh fh;
 __u32 cookie;
 __u32 count;
 u32 * buffer;
};

struct nfsd_attrstat {
 struct svc_fh fh;
 struct kstat stat;
};

struct nfsd_diropres {
 struct svc_fh fh;
 struct kstat stat;
};

struct nfsd_readlinkres {
 int len;
};

struct nfsd_readres {
 struct svc_fh fh;
 unsigned long count;
 struct kstat stat;
};

struct nfsd_readdirres {
 int count;

 struct readdir_cd common;
 u32 * buffer;
 int buflen;
 u32 * offset;
};

struct nfsd_statfsres {
 struct kstatfs stats;
};

union nfsd_xdrstore {
 struct nfsd_sattrargs sattr;
 struct nfsd_diropargs dirop;
 struct nfsd_readargs read;
 struct nfsd_writeargs write;
 struct nfsd_createargs create;
 struct nfsd_renameargs rename;
 struct nfsd_linkargs link;
 struct nfsd_symlinkargs symlink;
 struct nfsd_readdirargs readdir;
};

#define NFS2_SVC_XDRSIZE sizeof(union nfsd_xdrstore)

#endif
