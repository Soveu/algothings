#!/usr/bin/python

import subprocess
import random
import time

MAXN = 1000000

def createInput(x):
    n = random.randint(1, MAXN)
    s = bin(n)
    s = s[2:].replace('1', 'R').replace('0', 'O')
 
    i = ''
    i += str(len(s))
    i += '\n'
    i += s

    return (bytearray(str(n)+'\n', 'ascii'), 
            bytearray(i, 'ascii'))


def testBin(exe, inputfunc, timeout=1, tests=1000):
    for i in range(tests):
        expect, give = inputfunc(i)
        timep = time.perf_counter()

        proc = subprocess.run(
                [exe], 
                capture_output=True, 
                input=give, 
                check=True,
                timeout=timeout)

        deltatime = time.perf_counter() - timep
    
        if(expect == proc.stdout):
            print("Success! Time: %f" % deltatime)
        else:
            print('FAIL', proc.stdout)

if __name__ == '__main__':
    testBin('./a.out', createInput, tests=10)
