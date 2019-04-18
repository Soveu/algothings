#!/usr/bin/python3

import sys

P = 32
M = 1000000007

pw = []
res = 1
for i in range(200000):
    res *= P
    res %= M
    pw.append(res)

i = 0
for x in pw:
    i += 1
    if(i % 7 == 0):
        print()

    print("0x%X, " % x, end='', flush=False)        

