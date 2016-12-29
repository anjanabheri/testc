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

#
#main entry
def main():
    """
    main entry
    """
    # default log level
    logging.basicConfig(level=logging.INFO,
                        format='%(asctime)s %(levelname)s %(message)s')

    # command line option
    usage = """
            usage: %prog [-d <level>]
                         --mimfile <mimfile>
            """
    parser = OptionParser(usage)
    parser = OptionParser()
    parser.add_option("--mimfile", dest="mimfile", type='string',
                      help="input OAM MIM file")
    (options, args) = parser.parse_args()

    oammim = "OAM_MIM.xml"

    global xmlData
    xmlData = xml.dom.minidom.parse(oammim)

    global alarmTypeToNewType
    alarmTypeToNewType = {}
    global oamMimFile
    global mmapFile

    moClassList = xmlData.getElementsByTagName("MOClass")

    for classData in moClassList:
        className = classData.getAttribute("Name")
        attList = classData.getElementsByTagName("Attribute")
        for data in attList:
            name = data.getAttribute("Name")
            default = data.getAttribute("Default")
            #print("name: %s" %(name))
            if default == "":
                print("    <MOClass Name=\"%s\" Attribute=\"%s\" Default=\"\"/>" %(className, name))


# main
#
if __name__ == "__main__":
    main()
