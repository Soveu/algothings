#!/usr/bin/python

import random

MINN, MAXN = 1, 16
MINX, MAXX = 2, 1000

n = random.randint(MINN, MAXN)
print(n)

for _ in range(n):
    print(random.randint(MINX, MAXX), end=' ')

print()
