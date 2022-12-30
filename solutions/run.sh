#!/bin/bash

run_dir=$1
sol_file=${2:-Solution}
exe_file=main

g++ -std=c++2a $run_dir/$sol_file.cpp -o $exe_file -fsplit-stack -Wall -Wextra -Wshadow
cat test.inp | ./$exe_file
