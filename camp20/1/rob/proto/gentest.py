#!/usr/bin/python

import random, sys

MINH, MAXH = 4, 16
MINN, MAXN = 1, 5

h = random.randint(MINH, MAXH)
n = random.randint(MINN, MAXN)

print(h, file=sys.stderr)

print(n, h)
for _ in range(n):
    a = random.randint(0, h-1)

    if a == 0:
        b = random.randint(a+1, h-1)
    else:
        b = random.randint(a+1, h)

    print(a, b)

