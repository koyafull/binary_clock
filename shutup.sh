#!/bin/bash

a[0]=2
a[1]=3
a[2]=14
a[3]=15
a[4]=4
a[5]=17
a[6]=18
a[7]=27
a[8]=22
a[9]=25
a[10]=8
a[11]=9
a[12]=11
a[13]=1
a[14]=5
a[15]=6
a[16]=16
a[17]=21
a[18]=19
a[19]=26

for i in ${a[@]}; do
	echo $i
	echo $i > /sys/class/gpio/export
	sleep .1
	echo out > /sys/class/gpio/gpio$i/direction
	sleep .1
	echo 0 > /sys/class/gpio/gpio$i/value
done
