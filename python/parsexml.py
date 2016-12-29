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
    xmlData = xml.dom.minidom.parse("some.xml")

    companyList = xmlData.getElementsByTagName("Company")
    for company in companyList:
        name = company.getAttribute("Name")
        loc = company.getAttribute("Location")
        site = company.getAttribute("Site")
        sitee = company.getElement("Site")
        lens = len(site)
        print("Company: %s, Location: %s, site: %s" %(name, loc, site))
        print("lens: %s" %(lens))
        #if 'Site' in company.attrib:
            #print("Site Present")
        #else:
            #print("No Site for this company")


# main
#
if __name__ == "__main__":
    main()
