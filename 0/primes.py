#!/usr/bin/python
import math
import sys

def isPrime(a):
    if a==1:
        return True
    return a >1 and all(a%i for i in xrange(2, int(math.ceil(math.sqrt(a)))))

def main():    
    inp = sys.stdin.readlines()
    a = range(1, 53)
    b = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    d = dict(zip(b,a))
    for case in inp:
        case = case[:-1]
        n = sum(map(lambda x: d[x], list(case)))
        if isPrime(n):
            print("It is a prime word.")
        else:
            print("It is not a prime word.")
    
main()