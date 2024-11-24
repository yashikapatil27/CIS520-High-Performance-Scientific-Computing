#!/bin/bash

gcc -std=c99 -o Problem1_PartC Problem1_PartC.c

j=1
while [[ j -le 10 ]]
do
    i=2
    while [[ i -le 10 ]]
    do
        /usr/bin/time -f " %e" ./Problem1_PartC $((10**i))\n &>> Problem1_data_files/timing$j.dat
        ((i = i + 1))
    done
    ((j = j + 1))
done