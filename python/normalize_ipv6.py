#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap
import socket


def main():

    addr = "2000::2d10:0:0:0:0"
    internal = socket.inet_pton(socket.AF_INET6, addr)
    print socket.inet_ntop(socket.AF_INET6, internal)

# main
#
if __name__ == "__main__":
    main()


