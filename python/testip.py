#!/usr/bin/env python

import sys
import os
import re
import StringIO
import random
from mmap import mmap
import ast
import IPy

# IP address manipulation functions, dressed up a bit

import socket, struct

def dottedQuadToNum(ip):
    "convert decimal dotted quad string to long integer"
    return struct.unpack('L',socket.inet_aton(ip))[0]

def numToDottedQuad(n):
    "convert long int to dotted quad string"
    return socket.inet_ntoa(struct.pack('L',n))

def makeMask(n):
    "return a mask of n bits as a long integer"
    return (2L<<n-1)-1

def ipToNetAndHost(ip, maskbits):
    "returns tuple (network, host) dotted-quad addresses given IP and mask size"

    n = dottedQuadToNum(ip)
    m = makeMask(maskbits)

    host = n & m
    net = n - host

    return numToDottedQuad(net), numToDottedQuad(host)

def ip2int(ip):
    """
    Convert an IP string to int
    """
    return struct.unpack("!I", socket.inet_aton(ip))[0]

def int2ip(addr):
    """
    Convert an int to IP string
    """
    return socket.inet_ntoa(struct.pack("!I", addr))

def fun():

    prefix = "5.6.54.44/24"
    ipa = prefix.split("/")
    print "ipa[0]: %s" %(ipa[0])
    ipn = ip2int(ipa[0])
    maskn = ip2int("255.255.255.0")

    print "ip: %s" %(ipn)
    print "maskn: %s" %(maskn)

    nwn = ipn & maskn

    nw = int2ip(nwn)

    print "network: %s" %(nw)

def convertPrefLenToMaskInt():

    i = 0
    while i < 33:
        maskn = IPy._prefixlenToNetmask(i, 4)
        print "prefix_to_mask[%s] = %d" %(i, maskn)
        i = i + 1

def calcDottedNetmask(mask):
    bits = 0xffffffff ^ (1 << 32 - mask) - 1
    return socket.inet_ntoa(struct.pack('>I', bits))

def main():

    fun()

    for i in xrange(0, 33, 1):
        maskn = calcDottedNetmask(i)
        print "prefix_to_mask[%s] = %s %d" %(i, maskn, ip2int(maskn))

    return

def fun2():

    prefix = "4.5.6.8/24"

    ipa = prefix.split("/")

    ipn = IPy.IP(ipa[0]).int()
    maskn = IPy._prefixlenToNetmask(int(ipa[1]), 4)

    ipnew = ipn & maskn

    print "converted to ip back: %s" %(IPy.IP(ipnew))

    return


def fun3():

    ipa = "10.1.2.3"
    mask = "255.255.255.0"

    ipn = IPy.IP(ipa).int()
    maskn = IPy.IP(mask).int()

    print "converted to num: %s" %(ipn)

    print "mask number: %s" %(maskn)

    ipnew = ipn & maskn

    print "converted to ip back: %s" %(IPy.IP(ipnew))


    ipa = "4.5.6.8/24"
    #ipn = IPy.IP(ipa)

    print "netmask: %s" %(IPy._prefixlenToNetmask(24, 4))


# main
#
if __name__ == "__main__":
    main()


