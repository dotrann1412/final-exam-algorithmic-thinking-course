#!/bin/bash

# ./run.sh 01 02 --> run 2nd solution of problem 01
source_file=./Problem${1}/Solution${2}.cpp
exe_file=main

g++ -std=c++2a ${source_file} -o $exe_file -fsplit-stack -Wall -Wextra -Wshadow
cat test.inp | ./$exe_file