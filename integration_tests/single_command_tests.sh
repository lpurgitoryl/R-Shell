#!/bin/sh

INPUTS=("ls" "ls -a" "ls -l")

./../rshell ${INPUTS[2]}
./../rshell ${INPUTS[1]}
./../rshell ${INPUTS[0]}
