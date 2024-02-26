#!/bin/bash

#Author: Isaiah Vogt
#Author email: ivogt@csu.fullerton.edu
#CPSC 223C-01
#Due Date: 02/06/2024 11:59pm

#OS developed on: 11.1.0ubuntu4
#OS developed on: 11.1.04ubuntu4

#Triangle Trigonometry Data IO:

echo "Remove old un-needed files, if any."
rm *.o
rm *.out

echo "Compile the C main function search.c according to C standard 2017"
gcc -c -Wall -m64 -no-pie -o number.o assignment1.c -std=c2x -lm

echo "Link object files"
gcc -m64 -no-pie -o num.out number.o -std=c2x -lm

echo "Run the program \"Program\""
./num.out

echo "The bash file has terminated."