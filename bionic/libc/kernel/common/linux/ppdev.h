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
#define PP_IOCTL 'p'

#define PPSETMODE _IOW(PP_IOCTL, 0x80, int)

#define PPRSTATUS _IOR(PP_IOCTL, 0x81, unsigned char)
#define PPWSTATUS OBSOLETE__IOW(PP_IOCTL, 0x82, unsigned char)

#define PPRCONTROL _IOR(PP_IOCTL, 0x83, unsigned char)
#define PPWCONTROL _IOW(PP_IOCTL, 0x84, unsigned char)

struct ppdev_frob_struct {
 unsigned char mask;
 unsigned char val;
};
#define PPFCONTROL _IOW(PP_IOCTL, 0x8e, struct ppdev_frob_struct)

#define PPRDATA _IOR(PP_IOCTL, 0x85, unsigned char)
#define PPWDATA _IOW(PP_IOCTL, 0x86, unsigned char)

#define PPRECONTROL OBSOLETE__IOR(PP_IOCTL, 0x87, unsigned char)
#define PPWECONTROL OBSOLETE__IOW(PP_IOCTL, 0x88, unsigned char)

#define PPRFIFO OBSOLETE__IOR(PP_IOCTL, 0x89, unsigned char)
#define PPWFIFO OBSOLETE__IOW(PP_IOCTL, 0x8a, unsigned char)

#define PPCLAIM _IO(PP_IOCTL, 0x8b)

#define PPRELEASE _IO(PP_IOCTL, 0x8c)

#define PPYIELD _IO(PP_IOCTL, 0x8d)

#define PPEXCL _IO(PP_IOCTL, 0x8f)

#define PPDATADIR _IOW(PP_IOCTL, 0x90, int)

#define PPNEGOT _IOW(PP_IOCTL, 0x91, int)

#define PPWCTLONIRQ _IOW(PP_IOCTL, 0x92, unsigned char)

#define PPCLRIRQ _IOR(PP_IOCTL, 0x93, int)

#define PPSETPHASE _IOW(PP_IOCTL, 0x94, int)

#define PPGETTIME _IOR(PP_IOCTL, 0x95, struct timeval)
#define PPSETTIME _IOW(PP_IOCTL, 0x96, struct timeval)

#define PPGETMODES _IOR(PP_IOCTL, 0x97, unsigned int)

#define PPGETMODE _IOR(PP_IOCTL, 0x98, int)
#define PPGETPHASE _IOR(PP_IOCTL, 0x99, int)

#define PPGETFLAGS _IOR(PP_IOCTL, 0x9a, int)
#define PPSETFLAGS _IOW(PP_IOCTL, 0x9b, int)

#define PP_FASTWRITE (1<<2)
#define PP_FASTREAD (1<<3)
#define PP_W91284PIC (1<<4)

#define PP_FLAGMASK (PP_FASTWRITE | PP_FASTREAD | PP_W91284PIC)

