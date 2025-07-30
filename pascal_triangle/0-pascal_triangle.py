#!/usr/bin/python3
"""
This module provides a function to generate Pascal's Triangle.
"""


def pascal_triangle(n):
    """
    Generates Pascal's Triangle up to the nth row.

    Each row is constructed by summing adjacent elements from the previous row.
    The first and last elements of each row are always 1.

    Args:
        n (int): The number of rows of the triangle to generate. Must be an
                 integer.

    Returns:
        list of lists of int: A list where each inner list represents a row
                              of the triangle. Returns an empty list if n <= 0.
    """
    if n <= 0:
        return []

    # Initialize the triangle with the first row
    triangle = [[1]]

    # Generate subsequent rows from 1 up to n-1
    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]  # Each row starts with 1

        # Calculate the middle elements of the new row
        for j in range(len(prev_row) - 1):
            new_row.append(prev_row[j] + prev_row[j + 1])

        new_row.append(1)  # Each row ends with 1
        triangle.append(new_row)

    return triangle
