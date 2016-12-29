#!/usr/bin/env python

#In Python 3, raw_input is replaced by input itself

import sys
import os
import re

def something():
    diction = {}
    number = input("")
    i = int(number)
    while(i > 0):
        line = raw_input("")
        word = line.split()
        diction[word[0]] = word[1]
        i = i - 1

    while(1):
        line = raw_input()
        if line in diction:
            print("%s=%s" %(line, diction[line]))
        else:
            print("Not found")

something()

