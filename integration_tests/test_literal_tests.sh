#!/bin/sh

INPUTS = ("test -e src/main.cpp" "test -d header" "test -f README.md")

./../rshell ${INPUTS[2]}
./../rshell ${INPUTS[1]}
./../rshell ${INPUTS[0]} 