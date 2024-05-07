Push Swap
Overview
Push Swap is a simple algorithm project aimed at sorting a set of integers using two stacks and a specific set of instructions.

Rules and Operations
Stacks:
Two stacks are available, named a and b.
At the beginning:
Stack a contains a random amount of negative and/or positive numbers, which cannot be duplicated.
Stack b is empty.
Operations:
sa: Swap the first 2 elements at the top of stack a.
sb: Swap the first 2 elements at the top of stack b.
ss: sa and sb at the same time.
pa: Push the first element at the top of b and put it at the top of a.
pb: Push the first element at the top of a and put it at the top of b.
ra: Rotate up all elements of stack a by 1.
rb: Rotate up all elements of stack b by 1.
rr: ra and rb at the same time.
rra: Reverse rotate down all elements of stack a by 1.
rrb: Reverse rotate down all elements of stack b by 1.
rrr: rra and rrb at the same time.
Usage
To use the push_swap program, follow these steps:

Clone repository.
Run make command to compile.
Run the program with a list of integers as arguments.
Example:

shell
Copy code
$ ./push_swap 4 2 7 1 3
This will output the smallest set of instructions required to sort the given integers.
