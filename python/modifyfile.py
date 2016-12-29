#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap
from multiprocessing import Process
from os import rename, listdir


def main():

    fnames = listdir('.')

    for oldfname in fnames:
        if re.match("[0-9][0-9][0-9] .*", oldfname):
            newfname = oldfname[4:]
            print "%s %60s" %(oldfname, newfname)
            command = "mv \"" + oldfname + "\" \"" + newfname + "\""
            #os.system(command)
        elif re.match("[0-9].*", oldfname):
            print "file: %s" %(oldfname)


        #if oldfname.startswith("1"):
            #rename(oldfname, oldfname.replace(badprefix, '', 1))

# main
#
if __name__ == "__main__":
    main()


