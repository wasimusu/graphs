#!/usr/bin/env bash

cd test
git clone https://github.com/google/googletest.git
cd ..

cd benchmark
git clone https://github.com/google/benchmark.git
cd ..

mkdir build
cd build
cmake ..
make

pwd
./test/tests 
./graphs