#!/usr/bin/env python

#
# take inputs as OAM_MIM.xml to genereate
# HENBGW base class 
#

import sys
import os
import re
import xml.dom.minidom
import StringIO
import logging
import random
import shutil
from optparse import OptionParser
#from sets import Set
from mmap import mmap
from collections import defaultdict

#
#main entry
def main():
    """
    main entry
    """

    data = defaultdict(list)

    data["college"].append("blr")
    data["college"].append("mbr")
    data["college"].append("biet")
    data["eng"].append("dvg")
    data["mbbs"].append("dvg")

    for elem in data:
        print("elem: %s: %s" %(elem, data[elem]))
        #for sub in data[elem]:
        if 'dvg' in data[elem]:
            print("dvg found")
            #print("sub: %s" %(sub))
    

    
    if ('college' not in data):
        print("not found ")
        return
    else:
        print("found")

    if 'dvg' in data['eng']:
        print("correct")
    else:
        print("wrong")
        return



# main
#
if __name__ == "__main__":
    main()
