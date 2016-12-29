#!/usr/bin/env python

import sys
import os
import re
import StringIO
import random
from mmap import mmap
import json
from pprint import pprint

def main():

    with open('route.json') as data_file:
        data = json.load(data_file)

    #pprint(data)

    for route in data["route_show"]:
        #print "p: %s" %(route["prefix"])
        for nh in route["next_hop"]:
            if (nh["state"] == "gateway"):
                print "p: %s, nh: %s, scope: %s" %(route["prefix"], nh["via"], route["scope"])
            elif (nh["state"] == "non-dataplane interface"):
                print "p: %s, nh: %s, scope: %s" %(route["prefix"], nh["state"], route["scope"])
            else:
                print "p: %s, nh: %s, scope: %s" %(route["prefix"], nh["state"], route["scope"])


# main
#
if __name__ == "__main__":
    main()


