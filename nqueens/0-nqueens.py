#!/usr/bin/python3
"""
N-Queens puzzle solver
"""
import sys


def is_number(s):
    """Check if a string can be converted to an integer"""
    try:
        int(s)
        return True
    except ValueError:
        return False


def print_solution(board):
    """Print the solution in the required format"""
    solution = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                solution.append([i, j])
    print(solution)


def is_safe(board, row, col):
    """Check if a queen can be placed at board[row][col]"""
    # Check row
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal (top-left direction)
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal (bottom-left direction)
    for i, j in zip(range(row, len(board), 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, solutions):
    """Recursive utility function to solve N Queens problem"""
    # Base case: If all queens are placed
    if col >= len(board):
        print_solution(board)
        return

    # Try placing queen in each row of the current column
    for i in range(len(board)):
        if is_safe(board, i, col):
            # Place the queen
            board[i][col] = 1

            # Recur to place remaining queens
            solve_nqueens_util(board, col + 1, solutions)

            # Backtrack: Remove the queen (revert the change)
            board[i][col] = 0


def solve_nqueens(N):
    """Solve the N Queens problem"""
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    solve_nqueens_util(board, 0, solutions)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    N = sys.argv[1]

    if not is_number(N):
        print("N must be a number")
        sys.exit(1)

    N = int(N)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(N)
