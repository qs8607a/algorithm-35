#! /bin/bash
num_results=3;
count=0;
exp1=""
exp2=""
file="query.txt"

function get_url_1
{
 q=$1
 echo "http://10.100.8.31:2012/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=2&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp1&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1"
# echo "http://10.100.79.142:12105/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp1&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1"
}

function get_url_2 
{
 q=$1
 echo "http://10.100.8.32:2012/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=2&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp1&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1"
# echo "http://10.100.79.142:12105/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp2&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1"
}
cat $file | while read line
do
	query=$line
	count=$(($count+1))
	s1=`get_url_1 "$query"`
	s2=`get_url_2 "$query"`

	wget --http-user=yunrang --http-passwd=superman "$s1" -O data/$count.1.html
	wget --http-user=yunrang --http-passwd=superman "$s2" -O data/$count.2.html

#	cat data/$count.1.html | php get_url.php > data/$count.1.url
#	cat data/$count.2.html | php get_url.php > data/$count.2.url

#	diff data/$count.1.url data/$count.2.url > diff.txt 2>err


#	wget --http-user=yunrang --http-passwd=superman "$s1" -O data/$count.1.html
#	wget --http-user=yunrang --http-passwd=superman "$s2" -O data/$count.2.html

#	cat data/$count.1.html | php get_url.php > data/$count.1.url
#	cat data/$count.2.html | php get_url.php > data/$count.2.url

  baike_flag_1=`grep "navi_booster" data/$count.1.html | wc -l`
  baike_flag_2=`grep "navi_booster" data/$count.2.html | wc -l`
  if [ $baike_flag_1 -ge "1" -a $baike_flag_2 -ge "1" ]
  then
    echo $query
  fi
done
