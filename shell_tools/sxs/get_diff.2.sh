num_results=3;
count=0;

cat query.txt | while read line
do
	query=$line
	count=$(($count+1))

	wget --http-user=yunrang --http-passwd=superman "http://10.100.79.142:2012/searchi?q=$query&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=QualityTuner%3Afalse%2CAuthorityTuner%3Afalse&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1" -O data/$count.1.html

	wget --http-user=yunrang --http-passwd=superman "http://10.100.79.142:2012/searchi?q=$query&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1" -O data/$count.2.html

	cat data/$count.1.html | php get_url.php > data/$count.1.url
	cat data/$count.2.html | php get_url.php > data/$count.2.url

	diff data/$count.1.url data/$count.2.url > diff.txt 2>err

	diff_count=$?

	if [ $diff_count -ne 0 ]
	then
		n=0;
		while [ $n -ne 6 ]
		do

		wget --http-user=yunrang --http-passwd=superman "http://10.100.79.142:2012/searchi?q=$query&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=QualityTuner%3Afalse%2CAuthorityTuner%3Afalse&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1" -O data/$count.1.html

		wget --http-user=yunrang --http-passwd=superman "http://10.100.79.142:2012/searchi?q=$query&service_name=web_mixer&num_results=$num_results&sr_deb=0&be_deb=0&be_di_deb=0&sr_log=0&be_log=0&be_di_log=0&cache_debug=0&fetch_docid=0&results_per_domain=0&exp=&di_exp=&user_id=0&requester_id=0&session_id=0&restrict_topic_id=0&restrict_topic_tag=&restrict_question_id=0&skip=31&throttle=0&search_type=-1" -O data/$count.2.html


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


	echo $diff_count"\t"$query

	done
