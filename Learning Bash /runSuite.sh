#!/bin/bash

if [[ $# -ne 2 ]]; then
        echo "Expected 2 arguments. Try again." >&2
        exit 4
fi

for stem in $(cat $1); do

        TEMPFILE=$(mktemp)

        if [[ ! -f "$stem.expect" ]] || [[ ! -r "$stem.expect" ]]; then
                echo Expect file does not exist >&2
                exit 4
        fi
        if [[ -f "$stem.args" ]] && [[ -r "$stem.args" ]] && [[ -f "$stem.in" ]] && [[ -r "$stem.in" ]]; then
                $2 $(cat "$stem.args") < "$stem.in" > $TEMPFILE
        elif [[ -f "$stem.args" ]] && [[ -r "$stem.args" ]]; then
                $22 $(cat "$stem.args") > $TEMPFILE
        elif [ -f "$stem.in" ] && [ -r "$stem.in" ]; then
                $2 < "$stem.in" > $TEMPFILE
        else
                $2 > $TEMPFILE
        fi

        diff $TEMPFILE "$stem.expect" > /dev/null
        if [ $? -ne 0 ]; then
                echo Test failed: $stem
                echo Args:
                if [ -f "$stem.args" ] && [ -r "$stem.args" ]; then
                        cat "$stem.args"
                fi
                echo Input:
                if [ -f "$stem.in" ] && [ -r "$stem.in" ]; then
                        cat "$stem.in"
                fi
                echo Expected:
                cat "$stem.expect"
                echo Actual:
                cat $TEMPFILE
        fi
        rm $TEMPFILE

done

