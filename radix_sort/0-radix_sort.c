#include "sort.h"

/**
 * get_max - Finds the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
  int max_val;
  size_t i;

  if (array == NULL || size == 0)
    return (0);

  max_val = array[0];
  for (i = 1; i < size; i++)
  {
    if (array[i] > max_val)
      max_val = array[i];
  }
  return (max_val);
}

/**
 * counting_sort_radix - Sorts an array of integers by a significant digit
 * using the counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current exponent (1, 10, 100, ...), representing the
 * significant digit.
 * @output: A buffer to store the sorted array.
 */
void counting_sort_radix(int *array, size_t size, int exp, int *output)
{
  int count[10] = {0};
  size_t i;

  /* Store count of occurrences in count[] */
  for (i = 0; i < size; i++)
    count[(array[i] / exp) % 10]++;

  /* Change count[i] so that count[i] now contains actual */
  /* position of this digit in output[] */
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  /* Build the output array. Iterate backwards for stability */
  for (i = size - 1; (int)i >= 0; i--)
  {
    output[count[(array[i] / exp) % 10] - 1] = array[i];
    count[(array[i] / exp) % 10]--;
  }

  /* Copy the output array to array[], so that array[] now */
  /* contains sorted numbers according to current digit */
  for (i = 0; i < size; i++)
    array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Description: Prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
  int max_val;
  int exp;
  int *output; /* Output buffer */

  if (array == NULL || size < 2)
    return;

  max_val = get_max(array, size);

  /* Allocate memory for the output buffer */
  output = malloc(sizeof(int) * size);
  if (output == NULL)
    return;

  /* Perform counting sort for every digit. Note that instead */
  /* of passing digit number, exp is passed. exp is 10^i */
  /* where i is current digit number. */
  for (exp = 1; max_val / exp > 0; exp *= 10)
  {
    counting_sort_radix(array, size, exp, output);
    print_array(array, size);
  }

  free(output);
}
