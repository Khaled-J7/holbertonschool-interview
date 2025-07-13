#!/usr/bin/python3
"""
This module contains the function to calculate the perimeter of an island.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in the grid.

    The function iterates through each cell of the grid. If a cell is land (1),
    it adds 4 to the perimeter. It then checks for adjacent land cells to the
    right and below, and for each shared edge found, it subtracts 2 from the
    total perimeter.

    Args:
        grid (list of list of int): A 2D list representing the map, where
                                    0 is water and 1 is land.

    Returns:
        int: The total perimeter of the single island in the grid.
    """
    if not grid or not isinstance(grid, list):
        return 0

    height = len(grid)
    width = len(grid[0])
    perimeter = 0
    shared_edges = 0

    for r in range(height):
        for c in range(width):
            if grid[r][c] == 1:
                perimeter += 4
                # Check for shared edge with the cell below
                if r < height - 1 and grid[r + 1][c] == 1:
                    shared_edges += 1
                # Check for shared edge with the cell to the right
                if c < width - 1 and grid[r][c + 1] == 1:
                    shared_edges += 1

    # Each shared edge was counted once, but removes two sides
    return perimeter - (shared_edges * 2)
