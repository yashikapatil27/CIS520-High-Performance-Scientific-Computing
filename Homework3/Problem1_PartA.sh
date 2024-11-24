#!/bin/bash

i=2
while [[ i -le 8 ]]
do
	./p1pa $((10**i)) 10 1 >> Problem1_PartA.dat
	((i = i + 1))
done


