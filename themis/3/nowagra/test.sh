#!/bin/bash

for i in {1..10}; do
  [[ "`./test.py $i | ./a.out`" == "$i" ]] && echo OK || echo FAIL $i
done

