#!/usr/bin/env python

import sys
import os
import re
import xml.dom.minidom
import StringIO
import logging
import random
from mmap import mmap


def insert(string, searchString):
    loc = m.find(searchString)
    print("location: %s" %(loc))
    global fileSize
    m.resize(fileSize + len(string))
    m[loc+len(string):] = m[loc:fileSize]
    m[loc:loc+len(string)] = string

    m.seek(loc + len(string) + 1)
    fileSize = fileSize + len(string)

def insertAtCurrentPosition(string):
    loc = m.tell()
    print("location: %s" %(loc))
    global fileSize
    m.resize(fileSize + len(string))
    m[loc+len(string):] = m[loc:fileSize]
    m[loc:loc+len(string)] = string

    m.seek(loc + len(string) + 1)
    fileSize = fileSize + len(string)

def FindStringAndMovePositionAfterThat(searchString):
    position = m.find(searchString)
    print("find position: %s" %(position))
    if position == -1:
        return position
    m.seek(position + len(searchString) + 1)
    print("current position: %s" %(position + len(searchString) + 1))


def FindStringAndDeleteAfterThat(searchString, stringToDelete):
    position = m.find(searchString)
    print("position to delete: %s, string: %s" %(position, stringToDelete))
    if position == -1:
        return position
    global fileSize
    m[position + len(searchString): fileSize - len(stringToDelete)] = m[position + len(searchString) + len(stringToDelete) : fileSize]
    fileSize = fileSize - len(stringToDelete)
    m.resize(fileSize)
    print("position now: %s" %(position))
    m.seek(position)
    print("position now (seeked): %s" %(m.tell()))

    
def main():
    str = "add this"

    filename = "test"
    f = open(filename, 'r+')
    global m
    m = mmap(f.fileno(), os.path.getsize(filename))
    global fileSize
    fileSize = m.size()

    #loc = m.find("anjan")
    #m.seek(loc + len("anjan") + 1)

    #insert(str, ">")
    #insert(str, ">")
    #insert(str, ">")
    #print("current pos: %s" %(m.tell()))
    #str2="add this bigggggggggggggggg stringgggggggggggg"
    #insert(str2, ">")

    FindStringAndDeleteAfterThat("see", "how")
    print("Current position: %s" %(m.tell()))
    m.seek(m.tell() - 1)
    FindStringAndMovePositionAfterThat("see")
    insertAtCurrentPosition("BRIGHT")

    m.close()
    f.close()

# main
#
if __name__ == "__main__":
    main()


