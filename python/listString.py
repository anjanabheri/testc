#!/usr/bin/env python

import sys
import os
import re
import StringIO
import random

skipPreConfigMO = ["SCNBuffer", "CFLBuffer", "AVCNBuffer", "OCDNBuffer", "ATMQOS", "BearerQOS"]
    
def main():

    if "ATMQOS" in skipPreConfigMO:
        print("ATM is present")

# main
#
if __name__ == "__main__":
    main()


