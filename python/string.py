#!/usr/bin/env python

import sys
import os
import re
import StringIO
import random

def fun():
    some = "This is a test temp string"
    print("old string: %s" %(some))
    some = some.replace(r"te", "####")
    print("new string: %s" %(some))


def main():
    some = "O A *> 1.1.1.1"
    if "*>" in some:
        pos = some.find("*>")
        line = some[pos:]
    else:
        line = some
    print "%s" %line


# main
#
if __name__ == "__main__":
    main()


