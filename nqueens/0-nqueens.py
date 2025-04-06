#!/usr/bin/python3
"""
N-Queens puzzle solver
"""
import sys


def is_safe(board, row, col):
    """
    Check if a queen can be placed at board[row][col]

    Args:
        board: Current state of the board (queens placed so far)
        row: Row to check
        col: Column to check

    Returns:
        Boolean: True if safe, False otherwise
    """
    # Check for queens in the same column
    for i in range(row):
        if board[i] == col:
            return False

    # Check upper left diagonal
    i, j = row - 1, col - 1
    while i >= 0 and j >= 0:
        if board[i] == j:
            return False
        i -= 1
        j -= 1

    # Check upper right diagonal
    i, j = row - 1, col + 1
    while i >= 0 and j < len(board):
        if board[i] == j:
            return False
        i -= 1
        j += 1

    return True


def solve_nqueens(n):
    """
    Solve the N-Queens problem using backtracking

    Args:
        n: Size of the board (n x n)

    Returns:
        List of solutions, where each solution is a list of queen positions
    """
    solutions = []
    board = [-1] * n

    def solve_util(row):
        # Base case: If all queens are placed
        if row == n:
            # Format the solution as required: [[row, col], [row, col], ...]
            solution = [[i, board[i]] for i in range(n)]
            solutions.append(solution)
            return

        # Try placing a queen in each column of the current row
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                solve_util(row + 1)
                # Backtrack
                board[row] = -1

    # Start solving from the first row
    solve_util(0)
    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_nqueens(n)
    for solution in solutions:
        print(solution)
