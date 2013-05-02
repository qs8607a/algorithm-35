#! /bin/bash
num_results=3;
count=0;
#exp1="enable_intent_host_booster%3Atrue%2Cmix_intent_entity_with_max_fun%3Atrue"
#exp2="enable_intent_host_booster%3Atrue%2Cmix_intent_entity_with_max_fun%3Atrue"
#exp1=""
#exp1="relax_hub_page_restriction_for_music%3Atrue"
#exp1="searchroot_enable_qa_knowledge_per_page%3A1"
exp1="enable_exp_intent_booster%3Atrue"
exp2=""
file="query.txt"

function get_url_1
{
  q=$1
  echo "http://10.100.8.33:8019/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp1&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=0"
#echo "http://10.100.79.142:9105/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp1&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=0"
}

function get_url_2 
{
  q=$1
  echo "http://10.100.8.33:8019/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp2&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=0"
#echo "http://10.100.79.142:9106/searchi?q=$q&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=$exp2&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=0"
}
cat $file | while read line
do
	query=$line
	count=$(($count+1))
	s1=`get_url_1 "$query"`
	s2=`get_url_2 "$query"`

	wget --http-user=yunrang --http-passwd=superman "$s1" -O data/$count.1.html
	wget --http-user=yunrang --http-passwd=superman "$s2" -O data/$count.2.html

	cat data/$count.1.html | php get_url.php > data/$count.1.url
	cat data/$count.2.html | php get_url.php > data/$count.2.url

	diff data/$count.1.url data/$count.2.url > diff.txt 2>err

	diff_count=$?

	if [ $diff_count -ne 0 ]
	then
		n=0;
		while [ $n -ne 6 ]
		do
			wget --http-user=yunrang --http-passwd=superman "$s1" -O data/$count.1.html
			wget --http-user=yunrang --http-passwd=superman "$s2" -O data/$count.2.html

			cat data/$count.1.html | php get_url.php > data/$count.1.url
			cat data/$count.2.html | php get_url.php > data/$count.2.url

			diff data/$count.1.url data/$count.2.url > diff.txt 2>err
			diff_flag=$?
			diff_count=$((diff_count + $diff_flag))

			n=$((n+1))

			if [ $diff_flag -ne 1 ]
			then
				n=6;
			fi

		done

		if [ $diff_count -ne 7 ]
		then
			diff_count=0;
		fi

	fi

	echo $diff_count"	"$query

	done
