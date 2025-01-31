	#include <stdio.h>

	#include "sandpiles.h"

	/**
	 * print_grid - Prints a 3x3 grid.
	 * @grid: The grid to print.
	 *
	 * Return: void
	 */
	void print_grid(int grid[3][3]) {
	  int i, j;

	  printf("=\n");
	  for (i = 0; i < 3; i++) {
	    for (j = 0; j < 3; j++) {
	      if (j > 0)
	        printf(" ");
	      printf("%d", grid[i][j]);
	    }
	    printf("\n");
	  }
	}

	/**
	 * is_stable - Checks if the sandpile is stable.
	 * @grid: The grid to check.
	 *
	 * Return: 1 if stable, 0 otherwise.
	 */
	int is_stable(int grid[3][3]) {
	  int i, j;

	  for (i = 0; i < 3; i++) {
	    for (j = 0; j < 3; j++) {
	      if (grid[i][j] > 3) {
	        return (0);
	      }
	    }
	  }
	  return (1);
	}

	/**
	 * topple - Performs one toppling round.
	 * @grid: The grid to topple.
	 *
	 * Return: void
	 */
	void topple(int grid[3][3]) {
	  int temp_grid[3][3];
	  int i, j;

	  for (i = 0; i < 3; i++) {
	    for (j = 0; j < 3; j++) {
	      temp_grid[i][j] = grid[i][j];
	    }
	  }
	  for (i = 0; i < 3; i++) {
	    for (j = 0; j < 3; j++) {
	      if (temp_grid[i][j] > 3) {
	        grid[i][j] -= 4;
	        if (i > 0) {
	          grid[i - 1][j]++;
	        }
	        if (i < 2) {
	          grid[i + 1][j]++;
	        }
	        if (j > 0) {
	          grid[i][j - 1]++;
	        }
	        if (j < 2) {
	          grid[i][j + 1]++;
	        }
	      }
	    }
	  }
	}

	/**
	 * sandpiles_sum - Computes the sum of two sandpiles.
	 * @grid1: The first grid and result grid.
	 * @grid2: The second grid.
	 *
	 * Return: void
	 */
	void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
	  int i, j;

	  for (i = 0; i < 3; i++) {
	    for (j = 0; j < 3; j++) {
	      grid1[i][j] += grid2[i][j];
	    }
	  }

	  while (!is_stable(grid1)) {
	    print_grid(grid1);
	    topple(grid1);
	  }
	}