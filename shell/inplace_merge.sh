#!/bin/sh

a=(10 9 8 7 6 5 4 3 2 1)

function swap() {
	local i=$1
	local j=$j
	local tmp=${a[$i]}
	a[$i]=${a[$j]}
	a[$j]=$tmp
}

function reverce() {
	local left=$1
	local right=$2
	for((i=$left,j=$right;i<j;i++,j--));do
		swap $i $j
	done
}

function Convert() {
	local left=$1
	local mid=$2
	local right=$3
	reverce $left $mid
	reverce $(($mid+1)) $right 
	reverce $left $right 
}

function implace_merge() {
	local left=$1
	local mid=$2
	local right=$3
	local i=$left
	local j=$(($mid+1))

	while [[ $i -lt $j ]] && [[ $j -le $right ]]; do 
		while [[ $i -lt $j ]] && [[ ${a[i]} -le ${a[$j]} ]]; do
			((i=i+1))
		done

		local index=$j

		while [[ $j -le $right ]] && [[ ${a[j]} -lt ${a[$i]} ]];do
			((j=j+1))
		done

		Convert $i $(($index-1)) $(($j-1))
		((i=i+j-index))
	done
}

function merge_sort() {
	local n=$1
	for ((sz=1;sz<n;sz=sz+sz));do
		for ((i=0;i+sz<n;i+=2*sz));do
			local left=$i
			local mid=$(($i+$sz-1))
			local right=$(($i+$sz+$sz-1))
			if [ $right -ge $(($n-1)) ];then
				right=$(($n-1))
			fi
			implace_merge $left $mid $right
#			echo -n "merge_sort $left $mid $right: "
#			for item in ${a[*]}; do
#				echo -n " $item "
#			done
#			echo "end"
		done
	done
}

len=${a[*]}
echo "len: $len"
merge_sort $len

for item in ${a[*]};do
	echo "item: $item"
done
