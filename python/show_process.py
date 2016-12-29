#!/usr/bin/env python

import sys
import os
import re
from subprocess import check_output
import subprocess
import commands
import argparse
from time import sleep
import curses
from datetime import datetime

vrProcess = ['ifmgrd', 'configd', 'imi', 'nsm', 'dataplane', 'bgpd', 'ldpd', 'mribd', 'msdpd', 'oamd',
    'ospf6d', 'ospfd', 'pimd', 'ribd', 'ripd', 'ripngd', 'rsvpd', 'vplaned']

vrProcessName = ['IFMGR', 'CONFIGD', 'IMI', 'NSM', 'DATAPLANE', 'BGP', 'LDP', 'MRIB', 'MSDP', 'OAM',
    'OSPF6', 'OSPF', 'PIM', 'RIB', 'RIP', 'RIPNG', 'RSVP', 'VPLANED']

class Process:
    def __init__(self):
        self.process = "" 
        self.name = ""
        self.pid = 0
        self.memory = 0
        self.memPc = 0.0
        self.cpuPc = 0.0
        self.cpuRunning = 0
        self.priority = 0
        self.nice = 0
        self.timeUp = 0

data = {}
cpu_data = {}

def get_status(name):

    if (check_process_exists(name) == False):
        return "error"

    cmd = "pidof " + name + "| xargs ps -o pid,rss,%mem,%cpu,psr,pri,nice,etime"
    returnValue = commands.getstatusoutput(cmd)
    output = returnValue[1].splitlines()[1]
    out = output.split()
    return out

def get_mem(name):
    cmd = "cat /proc/meminfo | grep " + name + " | awk '{print $2}'"
    returnValue = commands.getstatusoutput(cmd)
    return float(returnValue[1])

def init_cpu_data():
    cmd = "top -bn1 | grep '^ ' | grep -v PID | awk '{print $1,$9}'"
    returnValue = commands.getstatusoutput(cmd)
    output = returnValue[1].splitlines()
    for data in output:
        out = data.split()
        cpu_data[out[0]] = out[1]

def get_cpu():
    cmd = "cat /proc/cpuinfo | grep processor | wc -l"
    returnValue = commands.getstatusoutput(cmd)
    return int(returnValue[1])

def get_total_cpu():
    totalCpu = 0.0
    for data in cpu_data:
        totalCpu += float(cpu_data[data])
    return totalCpu

def check_process_exists(name):
    try:
        check_output(["pidof", name])
    except subprocess.CalledProcessError, e:
        return False
    return True

def init():
    index = 0
    for proc in vrProcess:
        pr = Process()
        pr.process = proc
        pr.name = vrProcessName[index] 
        index = index + 1
        data[proc] = pr

    init_cpu_data()

def getData():
    for proc in data:
        output = get_status(data[proc].process)
        if (output == "error"):
            continue
        data[proc].pid = output[0]
        memory = float(output[1])

        data[proc].memory = str(format(round(memory / 1024, 2), '.2f')) + " M"
        data[proc].memPc = float(output[2])
        if data[proc].pid in cpu_data:
            data[proc].cpuPc = cpu_data[data[proc].pid]
        data[proc].cpuRunning = output[4]
        data[proc].priority = output[5]
        data[proc].nice = output[6]
        data[proc].timeUp = output[7]

def printLine():
    global gStr
    c = ""
    for i in xrange(84):
        c += "-"
    gStr += c + "\n"

def showSystem():
    printLine()
    cpu = get_cpu()
    totalCpu = get_total_cpu()
    totalMem = get_mem("MemTotal")
    freeMem = get_mem("MemFree")
    usedMem = float(totalMem - freeMem)
    out = "Total Memory: %4d %-42s %s %d\n" \
        %(float(totalMem/ 1024), "M", "Number of CPUs :", cpu)
    out += "Used Memory : %4d %s (%.1f%s %49s %.1f \n"\
        %(float(usedMem / 1024), "M", (usedMem/totalMem)*100,\
        "%)", "Total CPU Usage:", totalCpu)
    out += "Free Memory : %4d M\n" %(float(freeMem / 1024))

    global gStr
    gStr += out

def showProc():
    dname = {}
    sortedList = {}

    printLine()
    out = str("  %-13s %6s %12s %6s %6s %6s %10s %4s %9s"
        %("PROCESS", "PID", "MEMORY", "%MEM", "%CPU", "CPU", "PRIORITY", "NICE", "UPTIME"))
    #scr.addstr(0, 0, out)
    global gStr
    gStr += out + "\n"

    for proc in data:
        out = str("  %-13s %6s %12s %6s %6s %6s %6s %7s %10s"
            %(data[proc].name,
              data[proc].pid, 
              data[proc].memory, 
              data[proc].memPc, 
              data[proc].cpuPc, 
              data[proc].cpuRunning, 
              data[proc].priority, 
              data[proc].nice, 
              data[proc].timeUp))

        if (args.cpu is True):
            dname[str(data[proc].cpuPc) + data[proc].name] = out
            sortedList = sorted(dname.items(), reverse=True)
        elif (args.memory is True):
            dname[str(data[proc].memPc) + data[proc].name] = out
            sortedList = sorted(dname.items(), reverse=True)
        else:
            dname[data[proc].name] = out
            sortedList = sorted(dname.items())

    printLine()

    for out in sortedList:
        #scr.addstr(0, 0, out[1])
        gStr += out[1] + "\n"

    printLine()

class Reprinter:
    def __init__(self):
        self.text = ''

    def moveup(self, lines):
        for _ in range(lines):
            sys.stdout.write("\x1b[A")

    def reprint(self, text):
        # Clear previous text by overwritig non-spaces with spaces
        self.moveup(self.text.count("\n"))
        sys.stdout.write(re.sub(r"[^\s]", " ", self.text))

        # Print new text
        lines = min(self.text.count("\n"), text.count("\n"))
        self.moveup(lines)
        sys.stdout.write(text)
        self.text = text

def printData():

    global gStr

    gStr = ""

    init()
    getData()
    showSystem()
    showProc()
    scr.addstr(0,0,gStr)
    scr.refresh()

def main():

    parser = argparse.ArgumentParser(description='Arguements')

    parser.add_argument('-r', '--repeat', help = 'Continue the run', action="store_true", default=False)
    group = parser.add_mutually_exclusive_group()
    group.add_argument('-c', '--cpu', help = 'Sort on CPU', action="store_true", default=False)
    group.add_argument('-m', '--memory', help = 'Sort on memory', action="store_true", default=False)

    global args
    args = parser.parse_args()

    global scr
    scr = curses.initscr()

    global gStr

    if (args.repeat is True):
        while(1):
            try:
                printData()
                sleep(1)
            except KeyboardInterrupt:
                break
    else:
        printData()

    curses.endwin()

# main
#
if __name__ == "__main__":
    main()


