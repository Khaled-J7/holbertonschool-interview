# C - RegEx

## Description

This project is a deep dive into the fundamentals of regular expression matching. The goal is to build a function in C that can determine if a given string matches a specified pattern. The pattern can include two special characters:

* `.` (dot): Matches any single character.
* `*` (asterisk): Matches zero or more occurrences of the preceding character.

This task requires a purely recursive solution, adhering to the strict constraints of the Betty coding style and without the use of the standard C library functions. It's an excellent exercise in recursion, state management, and pointer manipulation.

## Files

* __`regex.h`__: Header file containing all function prototypes.
* __`regex.c`__: Source code for the regex_match function.
