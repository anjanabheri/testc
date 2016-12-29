#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap


def main():
    x = Test()

class Test2():
    flag = False
    def __init__(self):
        print "init Test2"

class Test():
    flag = False
    y = Test2()
    def __init__(self):
        print "init Test"

# main
#
if __name__ == "__main__":
    main()


