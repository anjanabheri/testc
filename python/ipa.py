#!/usr/bin/env python

import sys
import os
import re
import StringIO
import random
from mmap import mmap
import ipaddress

def main():
    ipa = "1.1.1.1/24"
    print "ip address input: %s" %(ipa)
    nw = ipaddress.ip_network(ipa, False)
    print "network: %s" %(nw.network_address)

# main
#
if __name__ == "__main__":
    main()


