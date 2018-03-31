#!/bin/bash

a=(10 9 8 7 6 5 4 3 2 1)
#a=(1 3 5 7 9 2 4 6 8 10)

function merge() {
	local low=$1
	local mid=$2
	local high=$3
	local i=$low
	local j=$(($mid+1))
	local id=0
	local b=()
	while [ $i -le $mid ] && [ $j -le $high ]; do
		#echo "hehe: $i $j ${a[$i]} ${a[$j]}"
		if [ ${a[$i]} -le ${a[$j]} ]; then
			b[$id]=${a[$i]}
			((i=i+1))
		else
			b[$id]=${a[$j]}
			((j=j+1))
		fi
		((id=id+1))
	done

	while [ $i -le $mid ]; do
		b[$id]=${a[$i]}
		((i=i+1))
		((id=id+1))
	done

	while [ $j -le $high ]; do
		b[$id]=${a[$j]}
		((j=j+1))
		((id=id+1))
	done

	for((i=$low;i<=$high;i++)); do
		id=$(($i-$low))
		a[i]=${b[id]}
	done
}

function mergesort() {
	local low=$1
	local high=$2
	if [ $low -ge $high ]; then
		return 0
	fi

	local mid=$(( ($low+$high)/2 ))
	mergesort $low $mid
	mergesort $(($mid+1)) $high
	merge $low $mid $high
}

len=${#a[*]}
echo "len=$len"

mergesort 0 $(($len-1))
#merge 0 4 9

for item in ${a[*]};do
	echo "haha: $item"
done

