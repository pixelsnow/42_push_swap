# 42_push_swap

🚧 In progress 🚧

## Summary

This project will make you sort data on a stack, with a limited set of instructions, using, the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.

Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

## The rules
- You have 2 stacks named a and b.
- At the beginning:
  - The stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack **b** is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
  - **sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - **sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - **ss** : sa and sb at the same time.
  - **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - **pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  - **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  - **rr** : ra and rb at the same time.
  - **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  - **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  - **rrr** : rra and rrb at the same time.
