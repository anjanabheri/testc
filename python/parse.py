#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap


def main():

    f = open('show_if_brief.txt', 'r');
    lines = f.read().splitlines()

    for line in lines:
        words = line.split()
        print "word 0 : %s" %words[1]


# main
#
if __name__ == "__main__":
    main()


