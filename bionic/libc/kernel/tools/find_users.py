#!/usr/bin/env python
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


#
# this program is used to find source code that includes linux kernel headers directly
# (e.g. with #include <linux/...> or #include <asm/...>)
#
# then it lists

import sys, cpp, glob, os, re, getopt
import kernel
from utils import *
from defaults import *


def usage():
    print """\
  usage:  find_users.py [-v] (file|directory|@listfile)+

    this program is used to scan a list of files or directories for
    sources that include kernel headers directly. the program prints
    the list of said source files when it's done.

    when scanning directories, only files matching the following
    extension will be searched: .c .cpp .S .h

    use -v to enable verbose output
"""
    sys.exit(1)


try:
    optlist, args = getopt.getopt( sys.argv[1:], 'v' )
except:
    # unrecognized option
    print "error: unrecognized option"
    usage()

for opt, arg in optlist:
    if opt == '-v':
        kernel.verboseSearch = 1
        kernel.verboseFind   = 1
    else:
        usage()

if len(args) < 1:
    usage()

# helper function used to walk the user files
def parse_file(path, parser):
    parser.parseFile(path)


# first, obtain the list of kernel files used by our clients
# avoid parsing the 'kernel_headers' directory itself since we
# use this program with the Android source tree by default.
#
fparser = kernel.HeaderScanner()
walk_source_files( args, parse_file, fparser, excludes=["kernel_headers","original"] )
files   = fparser.getFiles()

for f in sorted(files):
    print f

sys.exit(0)
