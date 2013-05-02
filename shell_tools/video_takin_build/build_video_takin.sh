#! /bin/bash
# Author: wangguangyuan@jike.com


function check_do
{
    __cmd=$1
    echo "${__cmd}"
    ${__cmd}
    if [ $? -eq 0 ] ; then
        echo "[succ]"
    else
        echo "[fail]"
        echo "[I will exit, sorry!!!]"
        exit 1
    fi
}

function usage
{
    echo "bash build_takin.sh y y y"

    echo "BUILD_MERGER"
    echo "BUILD_SORT"
    echo "BUILD_MAIN"
}

if [ $# -ne 3 ] ; then
    usage
    exit 1
fi

BUILD_MERGER=$1
BUILD_SORT=$2
BUILD_MAIN=$3

DEST=houyanhan@10.100.79.109:/home/houyanhan
#OPT="-i /home/yrservice/.ssh/id_rsa"
#CURRENT_DIR=`pwd`

if [ ${BUILD_MERGER} == "y" ] ; then
check_do "./devel/ymake/ymake.sh t=video/indexing/takin/building/public/..."
check_do "scp $OPT .ymake-out/dbg/video/indexing/takin/building/public/takin_doc_token_hit_creator_main $DEST"
fi

if [ ${BUILD_SORT} == "y" ] ; then
check_do "./devel/ymake/ymake.sh t=indexing/pipeline/mapreduce/takin_doc_sort/..."
check_do "scp $OPT .ymake-out/dbg/indexing/pipeline/mapreduce/takin_doc_sort/mr_takin_doc_sort $DEST"
fi

if [ ${BUILD_MAIN} == "y" ] ; then
check_do "./devel/ymake/ymake.sh t=video/indexing/takin/leaf/public/..."
check_do "scp $OPT .ymake-out/dbg/video/indexing/takin/leaf/public/takin_leaf_main $DEST"
fi

