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
#ifndef CAMERA_MT9T013_H
#define CAMERA_MT9T013_H
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/ioctl.h>
#include <asm/sizes.h>

#define MT9T013_I2C_IOCTL_MAGIC 'm'

#define MT9T013_I2C_IOCTL_W   _IOW(MT9T013_I2C_IOCTL_MAGIC, 0, unsigned)

#define MT9T013_I2C_IOCTL_R   _IOR(MT9T013_I2C_IOCTL_MAGIC, 1, unsigned)

#define MT9T013_I2C_IOCTL_AF_W   _IOW(MT9T013_I2C_IOCTL_MAGIC, 2, unsigned)

#define MT9T013_I2C_IOCTL_CAMIF_PAD_REG_RESET   _IO(MT9T013_I2C_IOCTL_MAGIC, 3)

#define MT9T013_I2C_IOCTL_CAMIF_PAD_REG_RESET_2   _IO(MT9T013_I2C_IOCTL_MAGIC, 4)

#define CAMERA_CONFIGURE_GPIOS   _IO(MT9T013_I2C_IOCTL_MAGIC, 7)

#define CAMERA_UNCONFIGURE_GPIOS   _IO(MT9T013_I2C_IOCTL_MAGIC, 8)

#define CAMERA_LENS_POWER_ON   _IO(MT9T013_I2C_IOCTL_MAGIC, 9)

#define CAMERA_LENS_POWER_OFF   _IO(MT9T013_I2C_IOCTL_MAGIC, 10)

#define MT9T013_I2C_IOCTL_CAMIF_APPS_RESET   _IO(MT9T013_I2C_IOCTL_MAGIC, 11)

#define CAMIO_VFE_MDC_CLK 1  
#define CAMIO_MDC_CLK 2  
#define CAMIO_VFE_CLK 3  

#define MT9T013_I2C_IOCTL_CLK_ENABLE   _IOW(MT9T013_I2C_IOCTL_MAGIC, 12, unsigned)

#define MT9T013_I2C_IOCTL_CLK_DISABLE   _IOW(MT9T013_I2C_IOCTL_MAGIC, 13, unsigned)

#define MT9T013_I2C_IOCTL_CLK_SELECT   _IOW(MT9T013_I2C_IOCTL_MAGIC, 14, unsigned)

#define MT9T013_I2C_IOCTL_CLK_FREQ_PROG   _IOW(MT9T013_I2C_IOCTL_MAGIC, 15, unsigned)

#define CAMSENSOR_REG_INIT 0<<0
#define CAMSENSOR_REG_UPDATE_PERIODIC 1<<0
#define CAMSENSOR_TYPE_PREVIEW 0<<1
#define CAMSENSOR_TYPE_SNAPSHOT 1<<1

#define MT9T013_I2C_IOCTL_SENSOR_SETTING   _IOW(MT9T013_I2C_IOCTL_MAGIC, 16, uint32_t)

struct mt9t013_reg_struct
{
 uint16_t vt_pix_clk_div;
 uint16_t vt_sys_clk_div;
 uint16_t pre_pll_clk_div;
 uint16_t pll_multiplier;
 uint16_t op_pix_clk_div;
 uint16_t op_sys_clk_div;
 uint16_t scale_m;
 uint16_t row_speed;
 uint16_t x_addr_start;
 uint16_t x_addr_end;
 uint16_t y_addr_start;
 uint16_t y_addr_end;
 uint16_t read_mode;
 uint16_t x_output_size ;
 uint16_t y_output_size;
 uint16_t line_length_pck;
 uint16_t frame_length_lines;
 uint16_t coarse_integration_time;
 uint16_t fine_integration_time;
};

struct mt9t013_reg_pat {
 struct mt9t013_reg_struct reg[2];
};

#define MT9T013_I2C_IOCTL_GET_REGISTERS   _IOR(MT9T013_I2C_IOCTL_MAGIC, 17, struct mt9t013_reg_pat *)

struct mt9t013_exposure_gain {
 uint16_t gain;
 uint16_t line;
 uint32_t mode;
};

#define MT9T013_I2C_IOCTL_EXPOSURE_GAIN   _IOW(MT9T013_I2C_IOCTL_MAGIC, 18, struct exposure_gain *)

#define MT9T013_I2C_IOCTL_MOVE_FOCUS   _IOW(MT9T013_I2C_IOCTL_MAGIC, 19, uint32_t)

#define MT9T013_I2C_IOCTL_SET_DEFAULT_FOCUS   _IOW(MT9T013_I2C_IOCTL_MAGIC, 20, uint32_t)

#define MT9T013_I2C_IOCTL_POWER_DOWN   _IO(MT9T013_I2C_IOCTL_MAGIC, 21)

struct mt9t013_init {
 int preview;
 uint16_t chipid;
};

#define MT9T013_I2C_IOCTL_INIT   _IOWR(MT9T013_I2C_IOCTL_MAGIC, 22, struct mt9t013_init *)

#endif

