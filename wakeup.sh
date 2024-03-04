#!/bin/bash

a[0]=14
a[1]=4
a[2]=15
a[3]=18
a[4]=17
a[5]=27
a[6]=24
a[7]=23
a[8]=22
a[9]=8
a[10]=25
a[11]=9
a[12]=10
a[13]=1
a[14]=7
a[15]=11
a[16]=16
a[17]=12
a[18]=6
a[19]=5

for i in ${a[@]}; do
	echo $i
	echo $i > /sys/class/gpio/export
	sleep .1
	echo out > /sys/class/gpio/gpio$i/direction
	sleep .1
	echo 1 > /sys/class/gpio/gpio$i/value
done
