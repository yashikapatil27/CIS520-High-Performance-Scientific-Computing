#!/bin/bash

i=1
while [[ i -le 30 ]]
do
	./Q1_C $((2**i))
	((i = i+1))
done