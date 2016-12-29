#!/usr/bin/env python

import sys
import os
import re
import string
import logging
import random
import datetime
import time
import socket
import struct

out = """
S    *> 100.1.1.1/32 [1/0] via 12.12.12.20, dp0s7
     *>              [1/0] via 12.12.12.19, dp0s7
     *>              [1/0] via 12.12.12.18, dp0s7
     *>              [1/0] via 12.12.12.17, dp0s7
     *>              [1/0] via 12.12.12.16, dp0s7
     *>              [1/0] via 12.12.12.15, dp0s7
     *>              [1/0] via 12.12.12.14, dp0s7
     *>              [1/0] via 12.12.12.13, dp0s7
      >              [1/0] via 12.12.12.12, dp0s7
      >              [1/0] via 12.12.12.11, dp0s7
      >              [1/0] via 12.12.12.10, dp0s7
S    *> 100.2.2.0/24 [1/0] via 12.12.12.10, dp0s7
S    *> 100.4.4.4/32 [1/0] via 100.1.1.1 (recursive via 12.12.12.13, dp0s7
                                                    via 12.12.12.14, dp0s7
                                                    via 12.12.12.15, dp0s7
                                                    via 12.12.12.16, dp0s7
                                                    via 12.12.12.17, dp0s7
                                                    via 12.12.12.18, dp0s7
                                                    via 12.12.12.19, dp0s7
                                                    via 12.12.12.20, dp0s7)
S       100.5.5.5/32 [1/0] via 34.34.34.34 inactive
B    *> 200.1.1.1/32 [20/0] via 12.12.12.20, dp0s7, 00:27:55
B    *> 200.2.2.0/24 [20/0] via 12.12.12.10, dp0s7, 00:27:55
"""

def rib():

    dest_parent = ""
    nh = ""

    f = open("rib_file", 'r')
    lines = f.read().splitlines()
    for line in lines:
        word = line.split()

        if (len(word) > 6) and (word[6] == '(recursive') and (word[1] == '*>'):
            dest_parent = word[2]
            dest = dest_parent
            nh = word[8]
        elif (len(word) > 0) and (word[0] == 'via'):
            dest = dest_parent
            nh = word[1]
        elif (len(word) > 4) and (word[4] == 'via') and (word[1] == '*>'):
            dest_parent = word[2]
            dest = dest_parent
            nh = word[5]
        elif (len(word) > 2) and (word[2] == 'via') and (word[0] == '*>'):
            dest = dest_parent
            nh = word[3]
        elif (len(word) > 3) and (word[3] == 'via') and (word[1] == '*>'):
            dest_parent = word[2]
            dest = dest_parent
            nh = word[4]
        else:
            print("not matching: %s" %line)
            continue

        print("d: %s nh: %s" %(dest, nh.replace(",", "")))

def ker():

    dest_parent = ""
    nh = ""

    ip_pattern = re.compile('(?:[0-9]{1,3}\.){3}[0-9]{1,3}')

    f = open("ker_file", 'r')
    lines = f.read().splitlines()
    for line in lines:
        word = line.split()

        if (len(word) > 1) and (word[0] == "default"):
            word[0] = "0.0.0.0/0"

        if (len(word) > 5) and (word[5] + word[6] == "scopelink"):
            continue
        elif (len(word) > 1) and (ip_pattern.search(word[0]) is not None) and (word[1] != "via"):
            dest_parent = word[0]
            continue
        elif (len(word) > 1) and (ip_pattern.search(word[0]) is not None) and (word[1] == "via"):
            dest = word[0]
            nh = word[2]
        elif (len(word) > 1) and (word[0] + word[1] == "nexthopvia"):
            dest = dest_parent
            nh = word[2]
        else:
            print("not matching: %s" %line)
            continue

        if "/" not in dest:
            dest = dest + "/32"

        print("d: %s nh: %s" %(dest, nh.replace(",", "")))

def dp():

    dest_parent = ""
    nh = ""

    ip_pattern = re.compile('(?:[0-9]{1,3}\.){3}[0-9]{1,3}')

    f = open("dp_file", 'r')
    lines = f.read().splitlines()
    for line in lines:
        word = line.split()

        if (len(word) > 2) and (word[1] + word[2] == "directlyconnected"):
            continue
        if (len(word) > 2) and (word[1] + word[2] == "non-dataplane interface"):
            continue
        elif (len(word) == 1) and (ip_pattern.search(word[0]) is not None):
            dest_parent = word[0]
            continue
        elif (len(word) > 1) and (ip_pattern.search(word[0]) is not None) and (word[1] == "via"):
            dest = word[0]
            nh = word[2]
        elif (len(word) > 1) and (word[0] == "nexthop") and (word[1] == "via"):
            dest = dest_parent
            nh = word[2]
        else:
            print("not matching: %s" %line)
            continue

        if "/" not in dest:
            dest = dest + "/32"

        print("d: %s nh: %s" %(dest, nh.replace(",", "")))

def main():

    #rib()
    ker()
    #dp()

    return

# main
#
if __name__ == "__main__":
    main()


