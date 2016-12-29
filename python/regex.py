#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap


def regex(var):

    p = re.compile('([0-9]|[1-9]\d{1,3}|[1-5]\d{4}|6[0-4]\d{3}|65[0-4]\d{2}|655[0-2]\d|6553[0-5])(?!\d)')
    m = p.match(var)

    if not m:
        print "%s: No Match" %var
    #else:
        #print "%s: Match" %var

list1 = ['00', '01', '065535']

def main():

    for i in range(0, 65540):
        regex(str(i))

    print "\nExtra strings \n";

    for i in list1:
        regex(i)

# main
#
if __name__ == "__main__":
    main()


