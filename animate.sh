#!/usr/bin/env bash
bash ./build.sh
while :
do
  clear
  {
    while :
    do
      echo
      sleep 0.1
    done
  } | ./hanoi 7
  sleep 2
done
