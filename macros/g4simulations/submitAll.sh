#!/bin/bash

#for INDIR in {4..23}
for INDIR in {0..23}
do
    if [[ INDIR == 20 || INDIR == 21 ]]
    then
        continue
    else 

        for DR in {2..5} #{2..5}
        do

#            for (( j=0; j<=1; j++ ))
#            for (( j=0; j<=9; j++ ))
#            do
#                bash submit.sh $INDIR $DR 00$j
#            done
        
#            for (( j=10; j<=99; j++ ))
            for (( j=10; j<=30; j++ ))
            do
                bash submit.sh $INDIR $DR 0$j
            done
        
#            for (( j=100; j<=399; j++ ))
#            do
#                bash submit.sh $INDIR $DR $j
#            done

        done # DR loop
    fi # INDIR if statement
done # INDIR loop

#wait $(jobs -p)



