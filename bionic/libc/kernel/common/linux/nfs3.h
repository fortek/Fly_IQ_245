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
#ifndef _LINUX_NFS3_H
#define _LINUX_NFS3_H

#define NFS3_PORT 2049
#define NFS3_MAXDATA 32768
#define NFS3_MAXPATHLEN PATH_MAX
#define NFS3_MAXNAMLEN NAME_MAX
#define NFS3_MAXGROUPS 16
#define NFS3_FHSIZE 64
#define NFS3_COOKIESIZE 4
#define NFS3_FIFO_DEV (-1)
#define NFS3MODE_FMT 0170000
#define NFS3MODE_DIR 0040000
#define NFS3MODE_CHR 0020000
#define NFS3MODE_BLK 0060000
#define NFS3MODE_REG 0100000
#define NFS3MODE_LNK 0120000
#define NFS3MODE_SOCK 0140000
#define NFS3MODE_FIFO 0010000

#define NFS3_ACCESS_READ 0x0001
#define NFS3_ACCESS_LOOKUP 0x0002
#define NFS3_ACCESS_MODIFY 0x0004
#define NFS3_ACCESS_EXTEND 0x0008
#define NFS3_ACCESS_DELETE 0x0010
#define NFS3_ACCESS_EXECUTE 0x0020
#define NFS3_ACCESS_FULL 0x003f

enum nfs3_createmode {
 NFS3_CREATE_UNCHECKED = 0,
 NFS3_CREATE_GUARDED = 1,
 NFS3_CREATE_EXCLUSIVE = 2
};

#define NFS3_FSF_LINK 0x0001
#define NFS3_FSF_SYMLINK 0x0002
#define NFS3_FSF_HOMOGENEOUS 0x0008
#define NFS3_FSF_CANSETTIME 0x0010

#define NFS3_FSF_DEFAULT 0x001B
#define NFS3_FSF_BILLYBOY 0x0018
#define NFS3_FSF_READONLY 0x0008

enum nfs3_ftype {
 NF3NON = 0,
 NF3REG = 1,
 NF3DIR = 2,
 NF3BLK = 3,
 NF3CHR = 4,
 NF3LNK = 5,
 NF3SOCK = 6,
 NF3FIFO = 7,
 NF3BAD = 8
};

struct nfs3_fh {
 unsigned short size;
 unsigned char data[NFS3_FHSIZE];
};

#define NFS3_VERSION 3
#define NFS3PROC_NULL 0
#define NFS3PROC_GETATTR 1
#define NFS3PROC_SETATTR 2
#define NFS3PROC_LOOKUP 3
#define NFS3PROC_ACCESS 4
#define NFS3PROC_READLINK 5
#define NFS3PROC_READ 6
#define NFS3PROC_WRITE 7
#define NFS3PROC_CREATE 8
#define NFS3PROC_MKDIR 9
#define NFS3PROC_SYMLINK 10
#define NFS3PROC_MKNOD 11
#define NFS3PROC_REMOVE 12
#define NFS3PROC_RMDIR 13
#define NFS3PROC_RENAME 14
#define NFS3PROC_LINK 15
#define NFS3PROC_READDIR 16
#define NFS3PROC_READDIRPLUS 17
#define NFS3PROC_FSSTAT 18
#define NFS3PROC_FSINFO 19
#define NFS3PROC_PATHCONF 20
#define NFS3PROC_COMMIT 21

#define NFS_MNT3_PROGRAM 100005
#define NFS_MNT3_VERSION 3
#define MOUNTPROC3_NULL 0
#define MOUNTPROC3_MNT 1
#define MOUNTPROC3_UMNT 3
#define MOUNTPROC3_UMNTALL 4

#ifdef NFS_NEED_KERNEL_TYPES

#define NFS3_POST_OP_ATTR_WORDS 22

#endif
#endif
