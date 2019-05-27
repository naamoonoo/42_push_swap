make db && RN=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`; ./push_swap $RN | ./checker $RN && echo $RN
