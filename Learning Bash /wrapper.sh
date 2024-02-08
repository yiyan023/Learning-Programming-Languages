#!/bin/bash

if [[ $# -eq 1 ]]; then
	if [[ -f $1.args ]] || [[ -r $1.args ]]; then
		if [[ -f $1.in ]] || [[ -r $1.in ]]; then 
			./arithmetic.sh $(cat $1.args) < $1.in
		else
			echo $1.in does not exist or is not readable. >&2
			exit 5
		fi 
	else 
		echo $1.args does not exist or is not readable. >&2
		exit 5
	fi
else
	echo "Usage: ./wrapper.sh <stem>" >&2
	exit 4
fi
