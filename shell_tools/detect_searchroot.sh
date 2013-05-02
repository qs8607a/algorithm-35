#!/bin/bash

replica_id=$1

processname="searchroot_00"

declare -i exist=`ps -ef | grep -v "grep" | grep -c "$processname"`
if [[ -z $exist || $exist < 1 ]]
then
    echo "There is not $processname."
    exit 2
else
    echo "There are $exist $processname."
    exit 0
fi
