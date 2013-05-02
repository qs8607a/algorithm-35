#!/bin/bash
root=$1
allfile="$root/all.log"
errfile="$root/err.log"
phoneconf="$root/phone.conf"
msg=""
declare -i fetcher_num
date=`date +%Y%m%d_%H:%M:%S`
echo "" >> $allfile
echo $date >> $allfile
for ip in `cat "$root"/ip.conf`
do    
    #log="$log $close_wait_num CLOSE_WAIT on $ip . "
    fetcher_num=`ssh "$ip" "ps -ef | grep fetcher_main -c"`
    echo "$ip $fetcher_num" >> $allfile
    restart=0
    #echo $fetcher_num
    if [ -z $fetcher_num ];
    then 
        restart=1
    else
        if  [ $fetcher_num -lt 3 ];
        then
            restart=1
        fi
    fi
    if [ $restart = 1 ];
    then
       #ssh $ip "echo hanzhongteng | sudo -S date"
       ssh $ip "cd /jike/image_fetcher/; ./clean.sh  >> /dev/null;" 
       ssh $ip "cd /jike/image_fetcher/; ./start.sh >> /dev/null;"
       echo "$date $ip clean and start. " >> $errfile
       msg="$msg ${ip:7:6} "
    fi
done

if [ -z "$msg" ];
then
   echo "Crawler fetcher is OK."
   exit 0
else
   echo "crawler fetcher: restart on $msg"
   exit 2
fi

#if [ -z "$msg" ];
#then
#    exit 0
#else
#    sendmsg="crawler fetcher: restart on $msg"
#    while read phoneno;
#    do
#        #echo wget -q --spider "http://192.168.10.25/database.php?phoneno=$phoneno&content=$msg"
#        wget -q --spider "http://192.168.10.25/database.php?phoneno=$phoneno&content=$sendmsg"
#    done < $phoneconf
#    exit 1
#fi
