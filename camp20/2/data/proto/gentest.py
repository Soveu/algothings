#!/usr/bin/python

from random import randint

daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

def gendate():
    year = randint(1900, 1910)
    month = randint(1, 12)
    
    if month == 2 and year != 1900 and year%4 == 0:
        day = randint(1, 29)
    else:
        day = randint(1, daysInMonth[month-1])
    
    hour = randint(0, 23)
    minute = randint(0, 59)
    second = randint(0, 59)
    
    return "%d-%02d-%02d %02d:%02d:%02d" % (year, month, day, hour, minute, second)

arr = sorted([gendate() for _ in range(2)])
if arr[0] == arr[1]:
    arr = sorted([gendate() for _ in range(2)])

for d in arr:
    print(d)

print(6)

