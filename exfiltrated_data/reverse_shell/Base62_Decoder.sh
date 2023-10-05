#!/bin/bash

input="$1"
grepout="$(grep -Fn 'FILE_START' $input)"
nums=""
suffix="1"
for i in $grepout
do
	IFS=':' read -ra split <<< "$i"
	num="$((split[0] + 1))"
	filestr="$(sed -n ${num}p $input)"
	echo "$filestr" | base64 -di > "file$suffix.out"
	((suffix++))
done
