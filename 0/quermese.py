#!/usr/bin/python
import sys


def main():
    inp = sys.stdin.readlines()
    counter = 0
    testNumber = 0
    for case in inp[:-1]:
        if (counter %2 == 0):
            counter+=1
            continue
        else:
            counter+=1
            testNumber+=1
            l = map(int, case.split())
            for i in range(len(l)):
                if l[i]==i+1:
                    print "Teste "+str(testNumber)
                    print l[i]
                    break
            
            
        
        
    
main()