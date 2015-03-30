#!/usr/bin/python
import sys

def numberOfMoves(n):
    return 2**n -1

def main():
    inp = sys.stdin.readlines()
    counter = 1
    for case[:-1] in inp[:-1]:
        print("Teste "+str(counter))
        counter+=1
        print str(numberOfMoves(int(case)))+"\n"
main()
