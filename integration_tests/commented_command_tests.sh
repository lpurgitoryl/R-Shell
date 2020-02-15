#!/bin/sh

INPUTS=("echo hello #howare tiy" "echo hello#world" "ls #-a" "ls #-j" "#" " #####" "# echo hello world" "ls#")

for input in "${INPUTS[@]}"
do
    echo "./rshell ${input}"
    ./rshell ${input}
done
