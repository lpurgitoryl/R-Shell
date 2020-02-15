#!/bin/sh

INPUTS=("echo hello exit" "ls -a && exit" "exit" "      exit" "ls exit" "echo hello; exit" "ls -a; exit" )

for input in "${INPUTS[@]}"
do
    echo "./rshell ${input}"
    ./rshell ${input}
done
