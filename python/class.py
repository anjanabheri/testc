#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap


class MyClass:
    """A simple example class"""
    i = 12345
    @staticmethod
    def f():
        return 'hello world'

def main():
    hi = MyClass.f()
    print "hi: %s" %(hi)

# main
#
if __name__ == "__main__":
    main()


