#!bin/bash

ARG=$(shuf -i 0-100 -n 10)
./push_swap $ARG #| ./checker_linux $ARG