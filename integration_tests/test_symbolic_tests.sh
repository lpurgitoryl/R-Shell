#!/bin/sh

INPUTS = ("[ -e src/main.cpp ]" "[ -d header ]" "[ -f README.md ]" "[ header/]")

./../rshell ${INPUTS[4]} 
./../rshell ${INPUTS[2]}
./../rshell ${INPUTS[1]}
./../rshell ${INPUTS[0]} 