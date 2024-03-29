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
#ifndef SUNRPC_SVC_H
#define SUNRPC_SVC_H

#include <linux/in.h>
#include <linux/sunrpc/types.h>
#include <linux/sunrpc/xdr.h>
#include <linux/sunrpc/svcauth.h>
#include <linux/wait.h>
#include <linux/mm.h>

struct svc_serv {
 struct list_head sv_threads;
 struct list_head sv_sockets;
 struct svc_program * sv_program;
 struct svc_stat * sv_stats;
 spinlock_t sv_lock;
 unsigned int sv_nrthreads;
 unsigned int sv_bufsz;
 unsigned int sv_xdrsize;

 struct list_head sv_permsocks;
 struct list_head sv_tempsocks;
 int sv_tmpcnt;

 char * sv_name;
};

#define RPCSVC_MAXPAYLOAD (64*1024u)

#define RPCSVC_MAXPAGES ((RPCSVC_MAXPAYLOAD+PAGE_SIZE-1)/PAGE_SIZE + 2)

struct svc_program {
 struct svc_program * pg_next;
 u32 pg_prog;
 unsigned int pg_lovers;
 unsigned int pg_hivers;
 unsigned int pg_nvers;
 struct svc_version ** pg_vers;
 char * pg_name;
 char * pg_class;
 struct svc_stat * pg_stats;
 int (*pg_authenticate)(struct svc_rqst *);
};

struct svc_version {
 u32 vs_vers;
 u32 vs_nproc;
 struct svc_procedure * vs_proc;
 u32 vs_xdrsize;

 int (*vs_dispatch)(struct svc_rqst *, u32 *);
};

typedef int (*svc_procfunc)(struct svc_rqst *, void *argp, void *resp);
struct svc_procedure {
 svc_procfunc pc_func;
 kxdrproc_t pc_decode;
 kxdrproc_t pc_encode;
 kxdrproc_t pc_release;
 unsigned int pc_argsize;
 unsigned int pc_ressize;
 unsigned int pc_count;
 unsigned int pc_cachetype;
 unsigned int pc_xdrressize;
};

typedef void (*svc_thread_fn)(struct svc_rqst *);

struct svc_serv * svc_create(struct svc_program *, unsigned int);

#endif
