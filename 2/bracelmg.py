#!/usr/bin/python

import sys

def main():
    inp = sys.stdin.readlines()[1:]
    for case in inp:
        substr = case.split()[0]
        text = case.split()[1]+case.split()[1]
        if substr in text:
            print "S"
        elif substr in text[::-1]:
            print "S"
        else:
            print "N"

main()
