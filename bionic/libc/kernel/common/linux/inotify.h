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
#ifndef _LINUX_INOTIFY_H
#define _LINUX_INOTIFY_H

#include <linux/types.h>

struct inotify_event {
 __s32 wd;
 __u32 mask;
 __u32 cookie;
 __u32 len;
 char name[0];
};

#define IN_ACCESS 0x00000001  
#define IN_MODIFY 0x00000002  
#define IN_ATTRIB 0x00000004  
#define IN_CLOSE_WRITE 0x00000008  
#define IN_CLOSE_NOWRITE 0x00000010  
#define IN_OPEN 0x00000020  
#define IN_MOVED_FROM 0x00000040  
#define IN_MOVED_TO 0x00000080  
#define IN_CREATE 0x00000100  
#define IN_DELETE 0x00000200  
#define IN_DELETE_SELF 0x00000400  
#define IN_MOVE_SELF 0x00000800  

#define IN_UNMOUNT 0x00002000  
#define IN_Q_OVERFLOW 0x00004000  
#define IN_IGNORED 0x00008000  

#define IN_CLOSE (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE)  
#define IN_MOVE (IN_MOVED_FROM | IN_MOVED_TO)  

#define IN_ONLYDIR 0x01000000  
#define IN_DONT_FOLLOW 0x02000000  
#define IN_MASK_ADD 0x20000000  
#define IN_ISDIR 0x40000000  
#define IN_ONESHOT 0x80000000  

#define IN_ALL_EVENTS (IN_ACCESS | IN_MODIFY | IN_ATTRIB | IN_CLOSE_WRITE |   IN_CLOSE_NOWRITE | IN_OPEN | IN_MOVED_FROM |   IN_MOVED_TO | IN_DELETE | IN_CREATE | IN_DELETE_SELF |   IN_MOVE_SELF)

#endif
