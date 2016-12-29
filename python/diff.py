#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap



    
def main():

    cmd = "diff <(cut -c 5- file1) <(cut -c 4- file2)"
    print ("command: %s" %(cmd))
    output = os.system(cmd)

    print ("output: %s" %(output))


# main
#
if __name__ == "__main__":
    main()


