CSC173 project5
Junfei Liu
jliu137@u.rochester.edu

I collaborate with Dingcheng Wang (dwang63@u.rochester.edu)

Our code can be compiled by
gcc -g -o run -std=c99 -Wall -Werror main.c Boolean.c Boolean.h Circuit.c Circuit.h Gates.c Gates.h strdup.c strdup.h

and you can run it by
./run.exe

This project implements three circuits:
circuit A: (x and y) or (not x)
circuit B: (x nor y) nor (x nor y)
circuit C: ((x or not y) and (y or not z)) and (z or not x)
all three functions that implement and return the circuits can be found in main.c.

The standard output includes the structures, test cases, and results clearly for all three required circuits.

We did not create methods corresponding to the NOR structure. Instead, we simply added a NOT gate after OR gate at
every occurrence of NOR gate.