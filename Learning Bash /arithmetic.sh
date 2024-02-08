#!/bin/bash

read n1 
read n2 
read n3

if [ $# -eq 1 ]; then 
	if [ $1 == a ]; then 
		if [ $((n1 + n2)) -eq $n3 ]; then 
			echo Yes
		else
			echo No
		fi
	elif [ $1 == s ]; then 
		if [ $((n1 - n2)) -eq $n3 ]; then 
			echo Yes 
		else
			echo No 
		fi 
	else
		echo Please choose a or s >&2
		exit 4
	fi
else
	echo Please input one coimmand line >&2
	exit 4
fi
