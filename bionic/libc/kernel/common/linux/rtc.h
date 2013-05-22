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
#ifndef _LINUX_RTC_H_
#define _LINUX_RTC_H_

struct rtc_time {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
};

struct rtc_wkalrm {
 unsigned char enabled;
 unsigned char pending;
 struct rtc_time time;
};

struct rtc_pll_info {
 int pll_ctrl;
 int pll_value;
 int pll_max;
 int pll_min;
 int pll_posmult;
 int pll_negmult;
 long pll_clock;
};

#define RTC_AIE_ON _IO('p', 0x01)  
#define RTC_AIE_OFF _IO('p', 0x02)  
#define RTC_UIE_ON _IO('p', 0x03)  
#define RTC_UIE_OFF _IO('p', 0x04)  
#define RTC_PIE_ON _IO('p', 0x05)  
#define RTC_PIE_OFF _IO('p', 0x06)  
#define RTC_WIE_ON _IO('p', 0x0f)  
#define RTC_WIE_OFF _IO('p', 0x10)  

#define RTC_ALM_SET _IOW('p', 0x07, struct rtc_time)  
#define RTC_ALM_READ _IOR('p', 0x08, struct rtc_time)  
#define RTC_RD_TIME _IOR('p', 0x09, struct rtc_time)  
#define RTC_SET_TIME _IOW('p', 0x0a, struct rtc_time)  
#define RTC_IRQP_READ _IOR('p', 0x0b, unsigned long)  
#define RTC_IRQP_SET _IOW('p', 0x0c, unsigned long)  
#define RTC_EPOCH_READ _IOR('p', 0x0d, unsigned long)  
#define RTC_EPOCH_SET _IOW('p', 0x0e, unsigned long)  

#define RTC_WKALM_SET _IOW('p', 0x0f, struct rtc_wkalrm) 
#define RTC_WKALM_RD _IOR('p', 0x10, struct rtc_wkalrm) 

#define RTC_PLL_GET _IOR('p', 0x11, struct rtc_pll_info)  
#define RTC_PLL_SET _IOW('p', 0x12, struct rtc_pll_info)  

#define RTC_IRQF 0x80  
#define RTC_PF 0x40
#define RTC_AF 0x20
#define RTC_UF 0x10

#endif
