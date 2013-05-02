#! /bin/bash
    
function just_do
{
    __cmd=$1
    echo "${__cmd}"
    ${__cmd}
    if [ $? -eq 0 ] ; then
        echo "[succ]"
    else
        echo "[fail]"
    fi  
}

path_segs=`echo $0| awk -F"/var/yr/|/search" '{print NF}'`
echo $path_segs
if [ $path_segs -ge 3 ]; then
  inst=`echo $0| awk -F"/var/yr/|/search" '{print $2}'`
else
  inst=`pwd| awk -F"/var/yr/|/search" '{print $2}'`
fi

id=`echo $inst | awk -F"_" '{printf("%d", $(NF-1))}'`
replica=`echo $inst | awk -F"_" '{printf("%d", $(NF))}'`
echo $inst, $id, $replica

yushu=0
let yushu=$id/4
let yushu=$yushu%2

__disk=/var/yr/dev/disk$yushu

just_do "mkdir -p ${__disk}/${inst}/takin_doc"
just_do "mkdir -p ${__disk}/${inst}/takin_index"
just_do "mkdir -p /var/yr/${inst}/search/data/"
just_do "ln -s ${__disk}/${inst}/takin_doc /var/yr/${inst}/search/data/takin_doc"
just_do "ln -s ${__disk}/${inst}/takin_index /var/yr/${inst}/search/data/takin_index"

echo "***********************************************"
echo "${inst} deployment over"
echo "***********************************************"

