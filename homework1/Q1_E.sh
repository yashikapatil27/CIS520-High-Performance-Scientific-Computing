#!/bin/bash

i=1
while [[ i -le 30 ]]
do
	./Q1_C.sh >> numbers$i.dat
	((i = i+1))
done
