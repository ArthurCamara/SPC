#!/usr/bin/python

import sys

def main():
    inp = map(int,sys.stdin.readlines()[1:])
    inp.sort()
    if len(inp)%2==1:
        med = len(inp)/2
        print inp[med]
    else:
        value = inp[len(inp)/2]+inp[(len(inp)/2)-1]
        print value/2



main()
