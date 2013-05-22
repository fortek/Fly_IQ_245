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

import sys, os, string, re

def usage():
    print """\
  usage:  genserv < /etc/services > netbsd/net/services.h

  this program is used to generate the hard-coded internet service list for the
  Bionic C library.
"""

re_service = re.compile(r"([\d\w\-_]+)\s+(\d+)/(tcp|udp)(.*)")
re_alias   = re.compile(r"([\d\w\-_]+)(.*)")

class Service:
    def __init__(self,name,port,proto):
        self.name    = name
        self.port    = port
        self.proto   = proto
        self.aliases = []

    def add_alias(self,alias):
        self.aliases.append(alias)

    def __str__(self):
        result  = "\\%0o%s" % (len(self.name),self.name)
        result += "\\%0o\\%0o" % (((self.port >> 8) & 255), self.port & 255)
        if self.proto == "tcp":
            result += "t"
        else:
            result += "u"

        result += "\\%0o" % len(self.aliases)
        for alias in self.aliases:
            result += "\\%0o%s" % (len(alias), alias)

        return result

def parse(f):
    result = []  # list of Service objects
    for line in f.xreadlines():
        if len(line) > 0 and line[-1] == "\n":
            line = line[:-1]
        if len(line) > 0 and line[-1] == "\r":
            line = line[:-1]

        line = string.strip(line)
        if len(line) == 0 or line[0] == "#":
            continue

        m = re_service.match(line)
        if m:
            service = Service( m.group(1), int(m.group(2)), m.group(3) )
            rest    = string.strip(m.group(4))

            while 1:
                m = re_alias.match(rest)
                if not m:
                    break
                service.add_alias(m.group(1))
                rest = string.strip(m.group(2))

            result.append(service)

    return result

services = parse(sys.stdin)
line = '/* generated by genserv.py - do not edit */\nstatic const char  _services[] = "\\\n'
for s in services:
    line += str(s)+"\\\n"
line += '\\0";\n'
print line

