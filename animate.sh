#!/usr/bin/env bash
bash ./build.sh
function exit_ok() {
  exit 0
}
trap exit_ok INT
while :
do
  {
    while :
    do
      echo -e '\e[K' > /dev/stderr
      echo
      sleep 0.1
    done
  } | ./hanoi 7
  sleep 2
done
