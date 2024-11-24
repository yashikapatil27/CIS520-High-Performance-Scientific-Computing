#/bin/bash
TIMEFORMAT=%R

gcc -o pc Q1_C.c

echo "N Runtime" > Q1_G.dat

i=1
while [[ i -le 30 ]]
do
    N=$((2**i))
    echo -n "$N " >> Q1_G.dat
    { time ./pc $N; } 2>> Q1_G.dat

    ((i = i + 1))
done
