#!/bin/bash

printf "%b\n\n" "					\033[1mTesting 3 random values between 0 and 10\033[0m"
i=0
while [ $i -lt 5 ]
do
	printf "Test $(($i + 1)):\n"
	ARG=$(seq 10 | shuf -n3)
	echo "Input: " $ARG
	printf "\n"
	./push_swap $ARG > _output
	./checker -f _output $ARG
	wc -l _output
	printf "\n"
	i=$((i + 1))
done

printf "%b\n\n" "					\033[1mTesting 5 random values between 0 and 10\033[0m"
i=0
while [ $i -lt 5 ]
do
	printf "Test $(($i + 1)):\n"
	ARG=$(seq 10 | shuf -n5)
	echo "Input: " $ARG
	printf "\n"
	./push_swap $ARG > _output
	./checker -f _output $ARG
	wc -l _output
	printf "\n"
	i=$((i + 1))
done

printf "%b\n\n" "					\033[1mTesting 100 random values between -100 and 100\033[0m"
i=0
while [ $i -lt 5 ]
do
	printf "Test $(($i + 1)):\n"
	ARG=$(seq -100 100 | shuf -n100)
	echo "Input: " $ARG
	printf "\n"
	./push_swap $ARG > _output
	./checker -f _output $ARG
	wc -l _output
	printf "\n"
	i=$((i + 1))
done

printf "%b\n\n" "					\033[1mTesting 500 random values between -500 and 500\033[0m"
i=0
while [ $i -lt 5 ]
do
	printf "Test $(($i + 1)):\n"
	ARG=$(seq -500 500 | shuf -n500)
	echo "Input: " $ARG
	printf "\n"
	./push_swap $ARG > _output
	./checker -f _output $ARG
	wc -l _output
	printf "\n"
	i=$((i + 1))
done

rm -f _output
