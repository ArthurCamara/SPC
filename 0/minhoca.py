#!/usr/bin/python
import sys

def main():
    inp = sys.stdin.readlines()
    nlines = int(inp[0].split()[0])
    ncolumns = int(inp[0].split()[1])
    highestLine = 0
    highestColumn = 0
    matrix = []
    for i in xrange(1, nlines+1):
        #sum lines
        a = map(int, inp[i].split())
        s = sum(a)
        if (s>highestLine):
            highestLine=s
        matrix.append(a)
    for i in xrange(ncolumns):
        s = sum(zip(*matrix)[i])
        if s > highestColumn:
            highestColumn = s
    if highestColumn>highestLine:
        print highestColumn
    else:
        print highestLine




main()
