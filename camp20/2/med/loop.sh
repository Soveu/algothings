#!/bin/bash

while true; do
  ./proto/gentest.py > /tmp/med.in;
  < /tmp/med.in ./brute > /tmp/brute.out;
  < /tmp/med.in ./wut > /tmp/wut.out;
  diff /tmp/brute.out /tmp/wut.out || break;
  echo GOOD

  echo GOT
  cat /tmp/wut.out
  echo

  echo DATA
  cat /tmp/med.in
  echo
  
  echo SORTED
  ./proto/sort.py < /tmp/med.in
  echo '------------------------'
done;

echo EXPECTED
cat /tmp/brute.out
echo

echo GOT
cat /tmp/wut.out
echo

echo DATA
cat /tmp/med.in
echo

echo SORTED
./proto/sort.py < /tmp/med.in

