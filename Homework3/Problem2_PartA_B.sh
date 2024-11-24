#!/bin/bash

i=2
while [[ i -le 8 ]]
do
	./p2pab $((10**i)) 10 4 >> Problem2_PartA_B.dat
	((i = i + 1))
done


