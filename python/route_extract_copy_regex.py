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

def fun():

    pat1 = re.compile('\[[0-9]{1,4}/[0-9]{1,4}\]')

    dest_parent = ""
    nh = ""

    f = open("show_file", 'r')
    lines = f.read().splitlines()
    for line in lines:
        words = line.split()

        if (len(words) > 6) and (words[6] == '(recursive') and (words[1] == '*>'):
            dest_parent = words[2]
            dest = dest_parent
            nh = words[8]
        elif (len(words) > 1) and (words[0] == 'via'):
            dest = dest_parent
            nh = words[1]
        elif (len(words) > 3) and (pat1.search(words[3]) is not None) and (words[1] == '*>'):
            dest_parent = words[2]
            dest = dest_parent
            nh = words[5]
        elif (len(words) > 3) and (pat1.search(words[1]) is not None) and (words[0] == '*>'):
            dest = dest_parent
            nh = words[3]
        elif (len(words) > 3) and (words[3] == 'via') and (words[1] == '*>'):
            dest_parent = words[2]
            dest = dest_parent
            nh = words[4]
        else:
            print("not matching: %s" %line)
            continue

        print("d: %s nh: %s" %(dest_parent, nh.replace(",", "")))

def main():

    global options

    fun()

    return

# main
#
if __name__ == "__main__":
    main()


