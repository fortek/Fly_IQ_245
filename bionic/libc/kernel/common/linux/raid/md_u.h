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
#ifndef _MD_U_H
#define _MD_U_H

#define RAID_VERSION _IOR (MD_MAJOR, 0x10, mdu_version_t)
#define GET_ARRAY_INFO _IOR (MD_MAJOR, 0x11, mdu_array_info_t)
#define GET_DISK_INFO _IOR (MD_MAJOR, 0x12, mdu_disk_info_t)
#define PRINT_RAID_DEBUG _IO (MD_MAJOR, 0x13)
#define RAID_AUTORUN _IO (MD_MAJOR, 0x14)
#define GET_BITMAP_FILE _IOR (MD_MAJOR, 0x15, mdu_bitmap_file_t)

#define CLEAR_ARRAY _IO (MD_MAJOR, 0x20)
#define ADD_NEW_DISK _IOW (MD_MAJOR, 0x21, mdu_disk_info_t)
#define HOT_REMOVE_DISK _IO (MD_MAJOR, 0x22)
#define SET_ARRAY_INFO _IOW (MD_MAJOR, 0x23, mdu_array_info_t)
#define SET_DISK_INFO _IO (MD_MAJOR, 0x24)
#define WRITE_RAID_INFO _IO (MD_MAJOR, 0x25)
#define UNPROTECT_ARRAY _IO (MD_MAJOR, 0x26)
#define PROTECT_ARRAY _IO (MD_MAJOR, 0x27)
#define HOT_ADD_DISK _IO (MD_MAJOR, 0x28)
#define SET_DISK_FAULTY _IO (MD_MAJOR, 0x29)
#define HOT_GENERATE_ERROR _IO (MD_MAJOR, 0x2a)
#define SET_BITMAP_FILE _IOW (MD_MAJOR, 0x2b, int)

#define RUN_ARRAY _IOW (MD_MAJOR, 0x30, mdu_param_t)
#define START_ARRAY _IO (MD_MAJOR, 0x31)
#define STOP_ARRAY _IO (MD_MAJOR, 0x32)
#define STOP_ARRAY_RO _IO (MD_MAJOR, 0x33)
#define RESTART_ARRAY_RW _IO (MD_MAJOR, 0x34)

typedef struct mdu_version_s {
 int major;
 int minor;
 int patchlevel;
} mdu_version_t;

typedef struct mdu_array_info_s {

 int major_version;
 int minor_version;
 int patch_version;
 int ctime;
 int level;
 int size;
 int nr_disks;
 int raid_disks;
 int md_minor;
 int not_persistent;

 int utime;
 int state;
 int active_disks;
 int working_disks;
 int failed_disks;
 int spare_disks;

 int layout;
 int chunk_size;

} mdu_array_info_t;

typedef struct mdu_disk_info_s {

 int number;
 int major;
 int minor;
 int raid_disk;
 int state;

} mdu_disk_info_t;

typedef struct mdu_start_info_s {

 int major;
 int minor;
 int raid_disk;
 int state;

} mdu_start_info_t;

typedef struct mdu_bitmap_file_s
{
 char pathname[4096];
} mdu_bitmap_file_t;

typedef struct mdu_param_s
{
 int personality;
 int chunk_size;
 int max_fault;
} mdu_param_t;

#endif

