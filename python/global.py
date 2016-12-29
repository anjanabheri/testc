#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap

def fun():
    global test
    test = 55
    
def main():
    global test
    test = 4
    print("test: %s" %(test))

    fun()
    print("test: %s" %(test))


# main
#
if __name__ == "__main__":
    main()


