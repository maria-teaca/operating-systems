#!/bin/bash

cd libc/
make clean
make

cd ../samples
make clean
make

cd ../tests
make clean
make -i

cd ..
