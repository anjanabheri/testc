#!/usr/bin/env python

import sys
import os
import re
import StringIO
import logging
import random
import shutil
from optparse import OptionParser
#from sets import Set
from mmap import mmap
from collections import defaultdict
import codecs
import subprocess
import matplotlib.pyplot as plt

def main():

    f = open("perf.data", 'r')
    line = f.readlines().split

    xaxis = []
    yaxis = []

    for data in line.split():
        yaxis.append(int(data))

    for n in xrange(100, 1100, 100):

        routes = str("%dK" %(n))
        if (n >= 1000):
            routes = str("%dM" %(n / 1000))

        xaxis.append(n)

    plt.plot(xaxis, yaxis)
    plt.show()


# main
#
if __name__ == "__main__":
    main()


