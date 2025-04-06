# Sorted Array to AVL Tree

A C program that converts a sorted array into a balanced AVL tree.

## Requirements

* Ubuntu 14.04 LTS
* GCC 4.8.4 with flags: -Wall -Werror -Wextra -pedantic
* Betty coding style

## Description

This project builds an AVL tree from a sorted array of integers. The algorithm ensures that:

* The resulting tree maintains the AVL property (balanced tree)
* No duplicate values are allowed in the array
* No rotations are needed since we build the tree optimally from the beginning

## Files

* `0-sorted_array_to_avl.c`: Contains the implementation of sorted_array_to_avl function
* `binary_trees.h`: Header file with all function prototypes and structure definitions
* `binary_tree_print.c`: Utility function to print the tree (provided by Holberton)

## Compilation & Execution

Compile the program with:

```powershell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

Run the executable:

```powershell
./0-sorted_array_to_avl
```

## Function Prototype

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

Where:

* `array` is a pointer to the first element of the array
* `size` is the number of elements in the array
* Returns a pointer to the root node of the created AVL tree, or NULL on failure
