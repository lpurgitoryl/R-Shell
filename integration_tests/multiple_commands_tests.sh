#!/bin/sh

INPUTS=("echo hello ; echo hai" "echo hello; ls #world" "ls #-a ; ls -a" "ls -j; echo sup" "#" " #####; ls" "# ; echo hello world")

for input in "${INPUTS[@]}"
do
    echo "./rshell ${input}"
    ./rshell ${input}
done
