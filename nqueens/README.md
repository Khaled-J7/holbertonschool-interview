# N Queens Puzzle Solver

This project implements a solution to the N Queens puzzle - placing N non-attacking queens on an N×N chessboard.

## Description

The N queens puzzle requires placing N queens on an N×N chessboard so that no two queens attack each other. This means no two queens can share the same row, column, or diagonal.

This implementation uses a backtracking algorithm to find all valid solutions for a given board size.

## Requirements

- Python 3.4.3 or later
- Ubuntu 14.04 LTS

## Usage

```
./0-nqueens.py N
```

Where N is an integer greater than or equal to 4 (the size of the chessboard).

### Examples

```
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]

$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

## Output Format

Solutions are printed as lists of queen positions, where each position is represented as [row, column], with both indices starting at 0.

## Algorithm

This implementation uses the backtracking approach:
1. Start in the leftmost column
2. Place a queen in each row of the current column if it's safe
3. For each placement, recursively place queens in the remaining columns
4. If we can't place a queen in any row of a column, backtrack to the previous column

