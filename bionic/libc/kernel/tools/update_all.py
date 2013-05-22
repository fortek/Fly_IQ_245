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
import sys, cpp, kernel, glob, os, re, getopt, clean_header
from defaults import *
from utils import *

def usage():
    print """\
  usage: %(progname)s

    this program is used to update all the auto-generated clean headers
    used by the Bionic C library. it assumes the following:

      - a set of source kernel headers is located in '../original',
        relative to the program's directory

      - the clean headers will be placed in '../arch-<arch>/asm',
        '../common/linux', '../common/asm-generic', etc..

      - if ANDROID_PRODUCT_OUT is defined in your environment, you're
        using the Android build system, and the program will issue
        p4 add / edit / delete commands to update the depot for you.
        (you'll need to p4 submit manually though)
""" % { "progname" : os.path.basename(sys.argv[0]) }
    sys.exit(0)

try:
    optlist, args = getopt.getopt( sys.argv[1:], '' )
except:
    # unrecognized option
    sys.stderr.write( "error: unrecognized option\n" )
    usage()

if len(optlist) > 0 or len(args) > 0:
    usage()

progdir = find_program_dir()
original_dir = os.path.normpath( progdir + "/../original" )
if not os.path.isdir( original_dir ):
    panic( "required directory does not exists: %s\n" % original_dir )

# find all source files in 'original'
#
sources = []
for root, dirs, files in os.walk( original_dir ):
    for file in files:
        base, ext = os.path.splitext(file)
        if ext == ".h":
            sources.append( "%s/%s" % (root,file) )

b = BatchFileUpdater()

for arch in kernel_archs:
    b.readDir( os.path.normpath( progdir + "/../arch-%s" % arch ) )

b.readDir( os.path.normpath( progdir + "/../common" ) )

#print "OLD " + repr(b.old_files)

for path in sources:
    dst_path, newdata = clean_header.cleanupFile(path)
    if not dst_path:
        continue

    b.readFile( dst_path )
    r = b.editFile( dst_path, newdata )
    if r == 0:
        r = "unchanged"
    elif r == 1:
        r = "edited"
    else:
        r = "added"

    print "cleaning: %-*s -> %-*s (%s)" % ( 35, path, 35, dst_path, r )

# We don't use Perforce anymore, but just in case, define ANDROID_USE_P4
# in your environment if you think you need it.
usePerforce = os.environ.has_key("ANDROID_USE_P4")

if usePerforce:
    b.updateP4Files()
else:
    b.updateFiles()

sys.exit(0)
