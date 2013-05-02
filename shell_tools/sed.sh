#!/bin/bash
function usage()
{
  echo "usage :$0 <old_value> <new_value> <directory_name>"
}

if [ $# -ne 3 ] ;then
  usage
  exit
fi

sed -i "s/$1/$2/g" `grep "$1" -rl "$3"`
