#!/usr/bin/env python

import sys
import os
import re
import StringIO
import random
from mmap import mmap
import json
from pprint import pprint

DP_IF_FILE = "/home/vyatta/dp.if"
DP_RT_FILE = "/home/vyatta/dp.rt"

def main():


    os.system("sudo /opt/vyatta/bin/vplsh -f 0 -c ifconfig | python -m json.tool > " + DP_IF_FILE);
    os.system("sudo /opt/vyatta/bin/vplsh -f 0 -c route | python -m json.tool > " + DP_IF_FILE);

    fr = open(DP_IF_FILE, 'r')
    data = json.load(fr)

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


