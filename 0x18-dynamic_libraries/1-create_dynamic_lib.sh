#!/bin/bash

# Compile C source files into object files
gcc -c -fPIC *.c

# Create a shared library named liball.so from the object files
gcc -shared -o liball.so *.o

# Add the current directory to the LD_LIBRARY_PATH
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

