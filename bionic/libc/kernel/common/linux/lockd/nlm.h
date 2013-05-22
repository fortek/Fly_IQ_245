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
#ifndef LINUX_LOCKD_NLM_H
#define LINUX_LOCKD_NLM_H

#define NLM_OFFSET_MAX ((s32) 0x7fffffff)
#define NLM4_OFFSET_MAX ((s64) ((~(u64)0) >> 1))

enum {
 NLM_LCK_GRANTED = 0,
 NLM_LCK_DENIED = 1,
 NLM_LCK_DENIED_NOLOCKS = 2,
 NLM_LCK_BLOCKED = 3,
 NLM_LCK_DENIED_GRACE_PERIOD = 4,
};

#define NLM_PROGRAM 100021

#define NLMPROC_NULL 0
#define NLMPROC_TEST 1
#define NLMPROC_LOCK 2
#define NLMPROC_CANCEL 3
#define NLMPROC_UNLOCK 4
#define NLMPROC_GRANTED 5
#define NLMPROC_TEST_MSG 6
#define NLMPROC_LOCK_MSG 7
#define NLMPROC_CANCEL_MSG 8
#define NLMPROC_UNLOCK_MSG 9
#define NLMPROC_GRANTED_MSG 10
#define NLMPROC_TEST_RES 11
#define NLMPROC_LOCK_RES 12
#define NLMPROC_CANCEL_RES 13
#define NLMPROC_UNLOCK_RES 14
#define NLMPROC_GRANTED_RES 15
#define NLMPROC_NSM_NOTIFY 16  
#define NLMPROC_SHARE 20
#define NLMPROC_UNSHARE 21
#define NLMPROC_NM_LOCK 22
#define NLMPROC_FREE_ALL 23

#endif
