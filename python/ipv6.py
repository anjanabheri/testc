#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import random
from mmap import mmap
import socket
import struct
from binascii import hexlify
import IPy

prefix_to_mask_v6 = []

def calc_dotted_netmask_v6(mask):
    bits = 0xffffffffffffffffffffffffffffffff ^ (1 << 128 - mask) - 1
    hi, lo = struct.unpack('!QQ', bits)
    #ip = socket.inet_ntop(socket.AF_INET6, str(bits))
    ip = (hi << 64) | lo


def fun():
    for i in xrange(0, 129, 1):
        maskn = calc_dotted_netmask_v6(i)
        prefix_to_mask_v6.append(maskn)


def main():

    fun()

    return

    ip = socket.inet_pton(socket.AF_INET6, "CAFE::1111")
    mask = socket.inet_pton(socket.AF_INET6, "FFFF::FF00")

    iphi, iplo = struct.unpack('!QQ', socket.inet_pton(socket.AF_INET6, "BAFE::2222"))
    nwhi, nwlo = struct.unpack('!QQ', socket.inet_pton(socket.AF_INET6, "FFFF::FF00"))

    rhi = iphi & nwhi
    rlo = iplo & nwlo

    ipn = struct.pack('!QQ', rhi, rlo)
    nw = socket.inet_ntop(socket.AF_INET6, ipn)

    print "nw: %s" %nw


# main
#
if __name__ == "__main__":
    main()


