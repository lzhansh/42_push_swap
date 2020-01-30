#!/bin/bash

ITERATIONS=0
LIMIT=700
FILE=numb
SUM=0

for i in {1..10}
do
        export ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
        NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
        if [ "$NUMBER" -gt "$LIMIT" ]
            then
            echo $NUMBER >> $FILE
            echo $ARG >> $FILE
        fi
        echo $i ":" $NUMBER
        let SUM+=$NUMBER;
        let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
