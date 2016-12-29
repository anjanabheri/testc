#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap
from multiprocessing import Process
import socket

def check_ipv6(n):
    try:
        socket.inet_pton(socket.AF_INET6, n)
        return True
    except socket.error:
        return False

def main():
    if check_ipv6("::1") is True:
        print "Valid"
    else:
        print "Invalid"


# main
#
if __name__ == "__main__":
    main()


