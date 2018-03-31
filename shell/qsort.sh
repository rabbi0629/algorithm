#!/bin/bash

a=(10 9 8 7 6 5 4 3 2 1)
#a=(1 3 5 7 9 2 4 6 8 10)

function swap() {
	local i=$1
	local j=$2
#	echo "before swap ${a[$i]} ${a[$j]}"
	local tmp=${a[$i]}
	a[$i]=${a[$j]}
	a[$j]=$tmp
#	echo "after swap ${a[$i]} ${a[$j]}"
}

function qsort() {
	local left=$1
	local right=$2

	#echo "left: $left right: $right"

	if [ $right -le $left ]; then 
		return 0
	fi

	local priv=${a[$left]}
	local i=$left
	local j=$right

	while [ $i -lt $j ]; do
		while [[ $i -lt $j ]] && [[ ${a[$j]} -ge $priv ]]; do
			((j=j-1))
		done
		
		while [[ $i -lt $j ]] && [[	${a[$i]} -le $priv ]]; do
			((i=i+1))
		done
		
		if [ $i -lt $j ]; then
			swap $i $j
		fi
	done

	swap $left $i

#	echo -n "qsort $left $i, $right: "
#	for item in ${a[*]}; do 
#		echo -n " $item "
#	done
#	echo " end "

	qsort $left $(($i-1))
	qsort $(($i+1)) $right 
}

len=${#a[*]}
echo "len=$len"

qsort 0 $(($len-1))

for item in ${a[*]};do
	echo "haha: $item"
done

