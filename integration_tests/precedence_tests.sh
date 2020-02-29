#!/bin/sh

INPUTS = ("(echo a || echo b) && (echo c || echo d)"  "(echo a || echo b) && echo c" "((echo a || echo b) && echo c)" "echo a && (echo b || echo c)")
./../rshell ${INPUTS[3]}
./../rshell ${INPUTS[2]}
./../rshell ${INPUTS[1]}
./../rshell ${INPUTS[0]} 