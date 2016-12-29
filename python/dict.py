#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap


test = {}

class Data():
    x = 0
    y = "SOME"

def add_data(x):
    data = Data()
    data.x = x * x
    test[x] = data

def main():

    add_data(1)
    add_data(3)
    add_data(6)
    add_data(2)
    add_data(7)

    for i in test:
        print "%d: %d" %(i, test[i].x)

# main
#
if __name__ == "__main__":
    main()


