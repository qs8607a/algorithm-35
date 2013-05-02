#! /bin/bash

path_segs=`echo $0| awk -F"/var/yr/|/search" '{print NF}'`
if [ $path_segs -ge 3 ]; then
  inst=`echo $0| awk -F"/var/yr/|/search" '{print $2}'`
else
  inst=`pwd| awk -F"/var/yr/|/search" '{print $2}'`
fi
id=`echo $inst | awk -F"_" '{printf("%d", $(NF-1))}'`
echo $inst, $id

HDFS_INPUT_PATH=/production/jk_video/offline_indexing_pipeline_old/takin/indexed_doc

HADOOP_BIN=/opt/hadoop/program/bin/hadoop

INDEX_PATH=/var/yr/$inst/search/data/takin_index
INPUT_PATH=/var/yr/$inst/search/data/takin_doc
INPUT_FILE=""
reduce_num=128
zero_num=5
leaf_num=1

function check_return_value
{
if [ $? -eq 0 ] ; then
  echo "ho, yeah"
else
  echo "fuck"
  exit 1
fi
}

function cp_from_hdfs
{

    rm $INPUT_PATH/*
    let "__count=reduce_num/leaf_num"
    let "__start=id*__count"
    let "__end=__start+__count"
    __tmp=0000000${reduce_num}
    __suffix=${__tmp:(-$zero_num):$zero_num}
    for ((__i=__start; __i<__end; __i++))
    do
        __tmp=0000000${__i}
        __prefix=${__tmp:(-$zero_num):$zero_num}
        __file=mr_takin_doc_sort-part-$__prefix-$__suffix
        echo $__file
        $HADOOP_BIN fs -copyToLocal $HDFS_INPUT_PATH/$__file $INPUT_PATH/
        check_return_value
    done
}

function build
{
    rm $INDEX_PATH/*
    cmd="./takin_doc_token_hit_creator_main
    --input_sstable_pattern=$INPUT_PATH/*
    --repos_file=$INDEX_PATH/takin
    --max_docs_built=4000000
    --attachment_processors=BasicAttachmentProcessor,VideoAttachmentProcessor,AnnotationAttachmentProcessor
    --doc_building_processors=WebContentProcessor,BasicWebPropertyProcessor,AnnotationSpecialTokenProcessor
    --annotation_names_for_filter_search_attachment=VideoDuration,VideoCopyright,VideoLive,VideoHd,VideoPubDate,VideoSite
    --indexing_use_doc_attr_repos=false
    --use_double_segmentation_format=true
    --splice_phrase=true
    --splice_low_idf_trigram=true
    --count_phrase_occurrence=true   
    --segmented_phrase_max_term_idf=50
    --low_idf_trigram_max_term_idf=30
    --phrase_token_blacklist_fname=/var/yr/$inst/static/yrdata/indexing/phrase_token_blacklist
    --low_idf_trigram_blacklist_fname=/var/yr/$inst/static/yrdata/indexing/low_idf_trigram_blacklist      
    --v=0
    "
    echo $cmd
    nohup $cmd
    check_return_value
}

function cp_to_hdfs
{
    __base=/production/jk_video/offline_indexing_pipeline/takin/index/$id
    __flag=Complete_`date +%Y%m%d_%H%M%S`
    $HADOOP_BIN fs -rmr $__base
    $HADOOP_BIN fs -mkdir $__base
    $HADOOP_BIN fs -copyFromLocal $INDEX_PATH/takin* $__base/
    $HADOOP_BIN fs -mkdir $__base/$__flag
}

#cp_from_hdfs
build
#cp_to_hdfs

