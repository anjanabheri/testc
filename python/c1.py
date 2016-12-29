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

    parser = OptionParser()

    parser.add_option('--routes', dest="number_of_routes", type=int, default=100,
                   help='number of routes')
    parser.add_option('--iter', dest="number_of_iters", type=int, default=1,
                   help='number of routes')
    parser.add_option("--debug", dest="debug", action="store_true",
                      help="to enable debug logs")
    parser.add_option("--dryrun", dest="dryrun", action="store_true",
                      help="to enable debug logs")
    (options, args) = parser.parse_args()

    if options.debug == True:
        logging.basicConfig(level=logging.DEBUG,
                        format='%(asctime)s %(levelname)s %(message)s')
    else:
        # default log level
        logging.basicConfig(level=logging.INFO,
                        format='%(asctime)s %(levelname)s %(message)s')

    logging.info("Performance Testing")

    xaxis = []
    yaxis = []

    global avg
    avg = {}

    for n in xrange(100, 1100, 100):

        routes = str("%dK" %(n))
        if (n >= 1000):
            routes = str("%dM" %(n / 1000))

        logging.info("Number of Routes: %s" %(routes))

        iter = options.number_of_iters
        total_time = 0

        for i in xrange(0, iter, 1):

            if (options.dryrun == True):
                output = "2015-07-30 17:11:06,776 INFO End. Total time taken: 4.64 seconds"
            else:
                output = subprocess.check_output("./rtaudit.py --folder show_outs/" + routes, stderr=subprocess.STDOUT, shell=True)

            f = open("/tmp/rta_scratch_pad/mod_outputs/rtvariance.log", 'r')
            lines = f.read().splitlines()
            f.close()

            for line in lines:
                if "Total time taken" in line:
                    time = float(line.split(" ")[7])
                    logging.info("Test<%d>: %f" %(i, time))
                    time = int(round(time, 0))
                    total_time += time

        avg[n] = total_time / iter

        logging.info("Average Time for <%d> iter - %5s: %d sec" %(iter, routes, avg[n]))

    logging.info("Graph: ")
    for n in xrange(100, 1100, 100):
        routes = str("%dK" %(n))
        if (n >= 1000):
            routes = str("%dM" %(n / 1000))

        dots = ""

        for i in xrange(0, avg[n], 1):
            dots += "-"

        print "%5s (%2d sec): %s" %(routes, avg[n], dots)

        xaxis.append(n)
        yaxis.append(avg[n])

    plt.plot(xaxis, yaxis)
    plt.show()

# main
#
if __name__ == "__main__":
    main()


