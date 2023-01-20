#!/bin/bash

clang -c fishhook.c -o fishhook.o
clang -c main.c -o main.o

echo "==== Testing with LD64 ===="
clang -arch arm64 fishhook.o main.o -o fishhook_test_ld64
./fishhook_test_ld64 fishhook.o


echo "==== Testing with Sold ===="
clang -arch arm64 fishhook.o main.o -o fishhook_test_sold -fuse-ld=$(pwd)/ld64.mold
./fishhook_test_sold fishhook.o
