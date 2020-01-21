#!/usr/bin/python

s = eval(input())
res = int(input())
print(sum([ res == x for x in s ]), len(s))
