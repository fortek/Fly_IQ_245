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
#ifndef _LINUX_NFS2_H
#define _LINUX_NFS2_H

#define NFS2_PORT 2049
#define NFS2_MAXDATA 8192
#define NFS2_MAXPATHLEN 1024
#define NFS2_MAXNAMLEN 255
#define NFS2_MAXGROUPS 16
#define NFS2_FHSIZE 32
#define NFS2_COOKIESIZE 4
#define NFS2_FIFO_DEV (-1)
#define NFS2MODE_FMT 0170000
#define NFS2MODE_DIR 0040000
#define NFS2MODE_CHR 0020000
#define NFS2MODE_BLK 0060000
#define NFS2MODE_REG 0100000
#define NFS2MODE_LNK 0120000
#define NFS2MODE_SOCK 0140000
#define NFS2MODE_FIFO 0010000

enum nfs2_ftype {
 NF2NON = 0,
 NF2REG = 1,
 NF2DIR = 2,
 NF2BLK = 3,
 NF2CHR = 4,
 NF2LNK = 5,
 NF2SOCK = 6,
 NF2BAD = 7,
 NF2FIFO = 8
};

struct nfs2_fh {
 char data[NFS2_FHSIZE];
};

#define NFS2_VERSION 2
#define NFSPROC_NULL 0
#define NFSPROC_GETATTR 1
#define NFSPROC_SETATTR 2
#define NFSPROC_ROOT 3
#define NFSPROC_LOOKUP 4
#define NFSPROC_READLINK 5
#define NFSPROC_READ 6
#define NFSPROC_WRITECACHE 7
#define NFSPROC_WRITE 8
#define NFSPROC_CREATE 9
#define NFSPROC_REMOVE 10
#define NFSPROC_RENAME 11
#define NFSPROC_LINK 12
#define NFSPROC_SYMLINK 13
#define NFSPROC_MKDIR 14
#define NFSPROC_RMDIR 15
#define NFSPROC_READDIR 16
#define NFSPROC_STATFS 17

#define NFS_MNT_PROGRAM 100005
#define NFS_MNT_VERSION 1
#define MNTPROC_NULL 0
#define MNTPROC_MNT 1
#define MNTPROC_UMNT 3
#define MNTPROC_UMNTALL 4

#endif
