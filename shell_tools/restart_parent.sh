#!/bin/bash

replica_id=$1
processname="goral_servlet"
self_name="restart_parent.sh"
sleep_time=5

if [ $# -ne 1 ]; 
then
  echo "Useage: ./restart_parent.sh replica_id"
  exit 1
fi

declare -i exist=`ps -ef | grep -v "grep" | grep -c "$self_name"`
if [ $exist -gt 2 ];
then
  echo "$self_name has started!"
  exit 1
fi

while [ 1 ]; do 
  declare -i exist=`ps -ef | grep -v "grep" | grep -c "$processname"`
  if [[ -z $exist || $exist < 1 ]]
  then
    echo "There is not $processname."
    cd /var/yr/goral_parent_000_0${replica_id}/search/bin
    ./run_goral_parent.sh start
  else
    echo "There are $exist $processname."
  fi
  sleep $sleep_time;
done
