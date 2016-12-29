#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import lxml
import StringIO
import logging
import random
import shutil
from optparse import OptionParser
#from sets import Set
from mmap import mmap
from collections import defaultdict
import codecs

    
def main():

    string = "phyb, phyc"
    list = split(",")
    for name in list:
        print("name: %s" %(name))

# main
#
if __name__ == "__main__":
    main()


