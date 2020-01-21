#!/bin/bash

TESTFILE='/tmp/date.in'
GOODFILE='/tmp/good.out'
BADFILE='/tmp/bad.out'

while true; do
  ./gentest.py > $TESTFILE
  ./jan < $TESTFILE > $GOODFILE
  ../a.out < $TESTFILE > $BADFILE
  diff -w $GOODFILE $BADFILE || break;
done;

echo INPUT
cat $TESTFILE
echo

echo JAN
cat $GOODFILE
echo

echo YOU
cat $BADFILE
echo '-------------------'

