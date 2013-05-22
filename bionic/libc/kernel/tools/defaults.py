# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.
#
# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.


# this module contains all the defaults used by the generation of cleaned-up headers
# for the Bionic C library
#

import time, os, sys
from utils import *

# the list of supported architectures
#
kernel_archs = [ 'arm', 'x86', 'sh' ]

# the list of include directories that belong to the kernel
# tree. used when looking for sources...
#
kernel_dirs = [ "linux", "asm", "asm-generic", "mtd" ]

# path to the directory containing the original kernel headers
#
kernel_original_path = os.path.normpath( find_program_dir() + '/../original' )

# a special value that is used to indicate that a given macro is known to be
# undefined during optimization
kCppUndefinedMacro = "<<<undefined>>>"

# this is the set of known macros we want to totally optimize out from the
# final headers
kernel_known_macros = {
    "__KERNEL__": kCppUndefinedMacro,
    "__KERNEL_STRICT_NAMES":"1",
    "__CHECKER__": kCppUndefinedMacro,
    "__CHECK_ENDIAN__": kCppUndefinedMacro,
    }

# define to true if you want to remove all defined(CONFIG_FOO) tests
# from the clean headers. testing shows that this is not strictly necessary
# but just generates cleaner results
kernel_remove_config_macros = True

# maps an architecture to a set of default macros that would be provided by
# toolchain preprocessor
kernel_default_arch_macros = {
    "arm": {},
    "x86": {"__i386__": "1"},
    }

# this is the set of known static inline functions that we want to keep
# in the final ARM headers. this is only used to keep optimized byteswapping
# static functions and stuff like that.
kernel_known_arm_statics = set(
       [ "___arch__swab32",    # asm-arm/byteorder.h
       ]
    )

kernel_known_x86_statics = set(
        [ "___arch__swab32",  # asm-x86/byteorder.h
          "___arch__swab64",  # asm-x86/byteorder.h
        ]
    )

kernel_known_sh_statics = set(
       [ "___arch__swab16",    # asm-sh/byteorder.h
         "___arch__swab32",    # asm-sh/byteorder.h
         "___arch__swab64",    # asm-sh/byteorder.h
         "__FD_ZERO",          # asm-sh/posix_types_32/64.h
         "__FD_SET",           # asm-sh/posix_types_32/64.h
       ]
    )

kernel_known_generic_statics = set(
        [ "__invalid_size_argument_for_IOC",  # asm-generic/ioctl.h
          "__cmsg_nxthdr",                    # linux/socket.h
          "cmsg_nxthdr",                      # linux/socket.h
          "ipt_get_target",
        ]
    )

# this maps an architecture to the set of static inline functions that
# we want to keep in the final headers
#
kernel_known_statics = {
        "arm" : kernel_known_arm_statics,
        "x86" : kernel_known_x86_statics,
        "sh" : kernel_known_sh_statics
    }

# this is a list of macros which we want to specifically exclude from
# the generated files.
#
kernel_ignored_macros = set(
        [ "MAXHOSTNAMELEN",  # for some reason, Linux defines it to 64
                             # while most of the BSD code expects this to be 256
                             # so ignore the kernel-provided definition and
                             # define it in the Bionic headers instead
        ]
    )

# this is the standard disclaimer
#
kernel_disclaimer = """\
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
"""
