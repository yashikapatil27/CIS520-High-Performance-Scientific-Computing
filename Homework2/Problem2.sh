#!/bin/bash

gcc -std=c99 -o Problem1_PartC Problem1_PartC.c

j=1
while [[ j -le 10 ]]
do

    for N in 10000000 100000000 1000000000

    do
        /usr/bin/time -f " %e" ./Problem1_PartC $N &>> Problem2_data_files/timing_laptop$j.dat

        # To run on anvil, use the following command
        # /usr/bin/time -f " %e" ./Problem1_PartC $N &>> Problem2_data_files/timing_anvil$j.dat

    done

    ((j = j + 1))
    
done
