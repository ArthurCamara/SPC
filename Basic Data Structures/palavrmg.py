#!/usr/bin/python
import sys

def main():
    inp = sys.stdin.readlines()[1:]
    for i in inp:
        w = i.lower()
        previous = 0
        flag = False
        for c in list(w[:-1]):
            if ord(c)<=previous:
                flag = True
                break
            previous = ord(c)
        if flag:
            print i[:-1]+": N"
        else:
            print i[:-1]+": O"




main()
