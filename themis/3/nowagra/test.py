#!/usr/bin/python

import sys

n = int(sys.argv[1])
x = (n + 1)
s = bin(x - 1)
s = s[2:].replace('1', 'R').replace('0', 'O')

print(len(s))
print(s)

