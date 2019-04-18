#!/usr/bin/python

with open('primes') as f:
    primes = [ int(x) for x in f.read().split() ]

sumArr = []
for i in range(2, len(primes)):
    sumArr += [ i for _ in range(primes[i] - primes[i-1]) ]

print(repr(sumArr)[1:-1].replace(',', ''))

