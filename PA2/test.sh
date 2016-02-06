#!/bin/bash
for i in 0.1 0.3 0.5 0.7 0.9
do
   for k in 0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0
   do
   		temp="gen_graphs/${i}_5000_10"
   		echo "${temp} ${k}"
   		echo -n "p = ${i} " >>5000new.out
     ./TestPrimDijk.out $temp ${k} >> 5000new.out
   done &
   wait
done &
wait