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
#ifndef _IPT_SCTP_H_
#define _IPT_SCTP_H_

#define IPT_SCTP_SRC_PORTS 0x01
#define IPT_SCTP_DEST_PORTS 0x02
#define IPT_SCTP_CHUNK_TYPES 0x04

#define IPT_SCTP_VALID_FLAGS 0x07

struct ipt_sctp_flag_info {
 u_int8_t chunktype;
 u_int8_t flag;
 u_int8_t flag_mask;
};

#define IPT_NUM_SCTP_FLAGS 4

struct ipt_sctp_info {
 u_int16_t dpts[2];
 u_int16_t spts[2];

 u_int32_t chunkmap[256 / sizeof (u_int32_t)];

#define SCTP_CHUNK_MATCH_ANY 0x01  
#define SCTP_CHUNK_MATCH_ALL 0x02  
#define SCTP_CHUNK_MATCH_ONLY 0x04  

 u_int32_t chunk_match_type;
 struct ipt_sctp_flag_info flag_info[IPT_NUM_SCTP_FLAGS];
 int flag_count;

 u_int32_t flags;
 u_int32_t invflags;
};

#define bytes(type) (sizeof(type) * 8)

#define SCTP_CHUNKMAP_SET(chunkmap, type)   do {   chunkmap[type / bytes(u_int32_t)] |=   1 << (type % bytes(u_int32_t));   } while (0)

#define SCTP_CHUNKMAP_CLEAR(chunkmap, type)   do {   chunkmap[type / bytes(u_int32_t)] &=   ~(1 << (type % bytes(u_int32_t)));   } while (0)

#define SCTP_CHUNKMAP_IS_SET(chunkmap, type)  ({   (chunkmap[type / bytes (u_int32_t)] &   (1 << (type % bytes (u_int32_t)))) ? 1: 0;  })

#define SCTP_CHUNKMAP_RESET(chunkmap)   do {   int i;   for (i = 0; i < ARRAY_SIZE(chunkmap); i++)   chunkmap[i] = 0;   } while (0)

#define SCTP_CHUNKMAP_SET_ALL(chunkmap)   do {   int i;   for (i = 0; i < ARRAY_SIZE(chunkmap); i++)   chunkmap[i] = ~0;   } while (0)

#define SCTP_CHUNKMAP_COPY(destmap, srcmap)   do {   int i;   for (i = 0; i < ARRAY_SIZE(chunkmap); i++)   destmap[i] = srcmap[i];   } while (0)

#define SCTP_CHUNKMAP_IS_CLEAR(chunkmap)  ({   int i;   int flag = 1;   for (i = 0; i < ARRAY_SIZE(chunkmap); i++) {   if (chunkmap[i]) {   flag = 0;   break;   }   }   flag;  })

#define SCTP_CHUNKMAP_IS_ALL_SET(chunkmap)  ({   int i;   int flag = 1;   for (i = 0; i < ARRAY_SIZE(chunkmap); i++) {   if (chunkmap[i] != ~0) {   flag = 0;   break;   }   }   flag;  })

#endif

