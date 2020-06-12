#!/usr/bin/env bash

cd test
git clone https://github.com/google/googletest.git
cd ..
mkdir build
cd build
cmake ..
make