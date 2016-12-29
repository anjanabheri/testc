#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap


def main():

    i = 1
    j = 1
    n = 0
    community = ""
    for i in xrange(1, 10, 1):
        for j in xrange(1, 15, 1):
            community = community + str(i) + ":" + str(j) + " "
            n = n + 1
            #print ("\"%s\"" %community)
            if len(community) > 540:
                print ("communities: %d, \"%s\"" %(n, community))
                return

# main
#
if __name__ == "__main__":
    main()


