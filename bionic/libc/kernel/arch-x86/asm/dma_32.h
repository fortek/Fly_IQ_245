/* Copyright Statement:
 * 
 * This software/firmware and related documentation ("MediaTek Software") are 
 * protected under relevant copyright laws. The information contained herein is 
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without 
 * the prior written permission of MediaTek inc. and/or its licensors, any 
 * reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly 
 * prohibited.  
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") 
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON 
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER 
 * DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF 
 * ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE 
 * MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR 
 * ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT 
 * IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER 
 * LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE 
 * RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S 
 * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. 
 * RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE 
 * LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, 
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
#ifndef _ASM_DMA_H
#define _ASM_DMA_H

#include <linux/spinlock.h>  
#include <asm/io.h>  
#include <linux/delay.h>

#ifdef HAVE_REALLY_SLOW_DMA_CONTROLLER
#define dma_outb outb_p
#else
#define dma_outb outb
#endif

#define dma_inb inb

#define MAX_DMA_CHANNELS 8

#define MAX_DMA_ADDRESS (PAGE_OFFSET+0x1000000)

#define IO_DMA1_BASE 0x00  
#define IO_DMA2_BASE 0xC0  

#define DMA1_CMD_REG 0x08  
#define DMA1_STAT_REG 0x08  
#define DMA1_REQ_REG 0x09  
#define DMA1_MASK_REG 0x0A  
#define DMA1_MODE_REG 0x0B  
#define DMA1_CLEAR_FF_REG 0x0C  
#define DMA1_TEMP_REG 0x0D  
#define DMA1_RESET_REG 0x0D  
#define DMA1_CLR_MASK_REG 0x0E  
#define DMA1_MASK_ALL_REG 0x0F  

#define DMA2_CMD_REG 0xD0  
#define DMA2_STAT_REG 0xD0  
#define DMA2_REQ_REG 0xD2  
#define DMA2_MASK_REG 0xD4  
#define DMA2_MODE_REG 0xD6  
#define DMA2_CLEAR_FF_REG 0xD8  
#define DMA2_TEMP_REG 0xDA  
#define DMA2_RESET_REG 0xDA  
#define DMA2_CLR_MASK_REG 0xDC  
#define DMA2_MASK_ALL_REG 0xDE  

#define DMA_ADDR_0 0x00  
#define DMA_ADDR_1 0x02
#define DMA_ADDR_2 0x04
#define DMA_ADDR_3 0x06
#define DMA_ADDR_4 0xC0
#define DMA_ADDR_5 0xC4
#define DMA_ADDR_6 0xC8
#define DMA_ADDR_7 0xCC

#define DMA_CNT_0 0x01  
#define DMA_CNT_1 0x03
#define DMA_CNT_2 0x05
#define DMA_CNT_3 0x07
#define DMA_CNT_4 0xC2
#define DMA_CNT_5 0xC6
#define DMA_CNT_6 0xCA
#define DMA_CNT_7 0xCE

#define DMA_PAGE_0 0x87  
#define DMA_PAGE_1 0x83
#define DMA_PAGE_2 0x81
#define DMA_PAGE_3 0x82
#define DMA_PAGE_5 0x8B
#define DMA_PAGE_6 0x89
#define DMA_PAGE_7 0x8A

#define DMA_MODE_READ 0x44  
#define DMA_MODE_WRITE 0x48  
#define DMA_MODE_CASCADE 0xC0  

#define DMA_AUTOINIT 0x10

#define isa_dma_bridge_buggy (0)

#endif
