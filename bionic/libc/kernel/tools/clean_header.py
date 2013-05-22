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

import sys, cpp, kernel, glob, os, re, getopt
from defaults import *
from utils import *

noUpdate = 1

def  cleanupFile( path ):
    """reads an original header and perform the cleanup operation on it
       this functions returns the destination path and the clean header
       as a single string"""
    # check the header path
    src_path    = path

    if not os.path.exists(src_path):
        if noUpdate:
            panic( "file does not exist: '%s'\n" % path )
        sys.stderr.write( "warning: file does not exit: %s\n" % path )
        return None, None

    if not os.path.isfile(src_path):
        if noUpdate:
            panic( "path is not a file: '%s'\n" % path )
        sys.stderr.write( "warning: not a file: %s\n" % path )
        return None, None

    original_path = kernel_original_path
    if os.path.commonprefix( [ src_path, original_path ] ) != original_path:
        if noUpdate:
            panic( "file is not in 'original' directory: %s\n" % path );
        sys.stderr.write( "warning: file not in 'original' ignored: %s\n" % path )
        return None, None

    src_path = src_path[len(original_path):]
    if len(src_path) > 0 and src_path[0] == '/':
        src_path = src_path[1:]

    if len(src_path) == 0:
        panic( "oops, internal error, can't extract correct relative path" )

    # convert into destination path, extracting architecture if needed
    # and the corresponding list of known static functions
    #
    arch = None
    re_asm_arch = re.compile( r"asm-([\w\d_\+\.\-]+)(/.*)" )
    m = re_asm_arch.match(src_path)
    statics = kernel_known_generic_statics
    if m and m.group(1) != 'generic':
        dst_path = "arch-%s/asm/%s" % m.groups()
        arch     = m.group(1)
        statics  = statics.union( kernel_known_statics.get( arch, set() ) )
    else:
        dst_path = "common/" + src_path

    dst_path = os.path.normpath( original_path + "/../" + dst_path )

    # now, let's parse the file
    #
    list = cpp.BlockParser().parseFile(path)
    if not list:
        sys.stderr.write( "error: can't parse '%s'" % path )
        sys.exit(1)


    list.optimizeMacros( kernel_known_macros )
    list.optimizeIf01()
    list.removeVarsAndFuncs( statics )
    list.removeComments()
    list.removeEmptyLines()
    list.removeMacroDefines( kernel_ignored_macros )
    list.insertDisclaimer( kernel.kernel_disclaimer )

    out = StringOutput()
    list.write(out)
    return dst_path, out.get()


if __name__ == "__main__":

    def usage():
        print """\
    usage:  %s [options] <header_path>

        options:
            -v    enable verbose mode

            -u    enabled update mode
                this will try to update the corresponding 'clean header'
                if the content has changed. with this, you can pass more
                than one file on the command-line

        <header_path> must be in a subdirectory of 'original'
    """ % os.path.basename(sys.argv[0])
        sys.exit(1)

    try:
        optlist, args = getopt.getopt( sys.argv[1:], 'uvk:' )
    except:
        # unrecognized option
        sys.stderr.write( "error: unrecognized option\n" )
        usage()

    for opt, arg in optlist:
        if opt == '-u':
            noUpdate = 0
        elif opt == '-v':
            verbose = 1
            D_setlevel(1)
        elif opt == '-k':
            kernel_original_path = arg

    if len(args) == 0:
        usage()

    if noUpdate:
        for path in args:
            dst_path, newdata = cleanupFile(path)
            print newdata

        sys.exit(0)

    # now let's update our files.

    b = BatchFileUpdater()

    for path in args:
        dst_path, newdata = cleanupFile(path)
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


    if os.environ.has_key("ANDROID_PRODUCT_OUT"):
        b.updateP4Files()
    else:
        b.updateFiles()

    sys.exit(0)
