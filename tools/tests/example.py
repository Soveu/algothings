#!/usr/bin/python

import random
import autotesting 

def createInput(x):
    x = random.random()
    return (
            bytearray("import time, sys; time.sleep(%f); sys.stdout.write('123')" % x, encoding='ascii'),
            bytearray('123', encoding='ascii'),
            )

if __name__ == '__main__':
    autotesting.run('python2', createInput, tests=10, timeout=0.95)

