#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap
from multiprocessing import Process


def main():

    if sys.argv[1] == "Swara":
        print "You are Swara. You like Dancing and Singing. You are a cute girl"
    elif sys.argv[1] == "Alaap":
        print "You are Alaap. You like Music and Drums. You are a naughty boy"
    elif sys.argv[1] == "Rishu":
        print "You are Rishu. You like cycle. You are a smart boy"
    elif sys.argv[1] == "Aayush":
        print "You are Aayush. You like playing and sleeping. You are becoming like Alaap"
    elif sys.argv[1] == "Sandhu":
        print "You are big Dabba !!!!!!!!"
    elif sys.argv[1] == "Chaithra":
        print "You are Chaithra.. You are a small Dabba !!!"
    elif sys.argv[1] == "Gyarry":
        print "You are Gyarry Chikkappa. You are big Dabba TV"
    else:
        print "I dont know who are you...."


# main
#
if __name__ == "__main__":
    main()


