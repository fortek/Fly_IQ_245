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
#ifndef _LINUX_RELAY_H
#define _LINUX_RELAY_H

#include <linux/types.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/list.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/kref.h>

#define FIX_SIZE(x) ((((x) - 1) & PAGE_MASK) + PAGE_SIZE)

#define RELAYFS_CHANNEL_VERSION 6

struct rchan_buf
{
 void *start;
 void *data;
 size_t offset;
 size_t subbufs_produced;
 size_t subbufs_consumed;
 struct rchan *chan;
 wait_queue_head_t read_wait;
 struct work_struct wake_readers;
 struct dentry *dentry;
 struct kref kref;
 struct page **page_array;
 unsigned int page_count;
 unsigned int finalized;
 size_t *padding;
 size_t prev_padding;
 size_t bytes_consumed;
 unsigned int cpu;
} ____cacheline_aligned;

struct rchan
{
 u32 version;
 size_t subbuf_size;
 size_t n_subbufs;
 size_t alloc_size;
 struct rchan_callbacks *cb;
 struct kref kref;
 void *private_data;
 size_t last_toobig;
 struct rchan_buf *buf[NR_CPUS];
};

struct rchan_callbacks
{

 int (*subbuf_start) (struct rchan_buf *buf,
 void *subbuf,
 void *prev_subbuf,
 size_t prev_padding);

 void (*buf_mapped)(struct rchan_buf *buf,
 struct file *filp);

 void (*buf_unmapped)(struct rchan_buf *buf,
 struct file *filp);

 struct dentry *(*create_buf_file)(const char *filename,
 struct dentry *parent,
 int mode,
 struct rchan_buf *buf,
 int *is_global);

 int (*remove_buf_file)(struct dentry *dentry);
};

struct rchan *relay_open(const char *base_filename,
 struct dentry *parent,
 size_t subbuf_size,
 size_t n_subbufs,
 struct rchan_callbacks *cb);

#endif

