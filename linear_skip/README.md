# Linear Search in Skip List

This project implements a linear search algorithm in a skip list data structure.

## Description

A skip list is an enhanced linked list that allows for faster search operations by maintaining "express lanes" - pointers that skip multiple elements, reducing the number of elements we need to check during a search.

The `linear_skip` function in this project searches for a value in a sorted skip list of integers using the express lane to optimize the search process.

## Files

- `search.h`: Header file containing the skiplist structure definition and function prototypes.
- `0-linear_skip.c`: Implementation of the linear search in a skip list algorithm.

## Compilation

The program can be compiled with:

```c
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```

## Algorithm

The search algorithm works in two phases:

1. Express lane search: Use the express pointers to quickly find a range where the target value might exist.
2. Linear search: Once the range is found, perform a regular linear search within that range.

## Time Complexity

The time complexity of this algorithm is O(√n), where n is the number of elements in the skip list.
