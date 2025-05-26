#include "holberton.h"

/**
 * _putchar - Writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * (Note: This function is provided by the testing environment.)
 */
int _putchar(char c)
{
  /*
   * This is a dummy implementation for compilation purposes.
   * The actual _putchar function will be linked during testing.
   */
  (void)c; /* Suppress unused parameter warning */
  return (1);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
  int len = 0;

  while (s[len] != '\0')
  {
    len++;
  }
  return (len);
}

/**
 * _is_digit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

/**
 * _print_error_and_exit - Prints "Error" to stdout and exits with status 98.
 */
void _print_error_and_exit(void)
{
  char *err = "Error\n";
  int i = 0;

  while (err[i] != '\0')
  {
    _putchar(err[i]);
    i++;
  }
  exit(98);
}

/**
 * _initialize_result_buffer - Initializes a character buffer with '0's
 * and a null terminator.
 * @buffer: The buffer to initialize.
 * @len: The length of the buffer (excluding the null terminator).
 */
void _initialize_result_buffer(char *buffer, int len)
{
  int i;

  for (i = 0; i < len; i++)
  {
    buffer[i] = '0';
  }
  buffer[len] = '\0';
}

/**
 * _multiply - Multiplies two positive numbers represented as strings.
 * @num1: The first number string.
 * @num2: The second number string.
 *
 * This function performs long multiplication, allocates memory for the result,
 * calculates the product, and prints the result to stdout.
 * It handles memory allocation failures by calling _print_error_and_exit.
 */
void _multiply(char *num1, char *num2)
{
  int len1, len2, total_len;
  char *result;
  int i, j, product, carry;

  len1 = _strlen(num1);
  len2 = _strlen(num2);
  total_len = len1 + len2;

  /* Allocate memory for the result buffer */
  result = malloc(sizeof(char) * (total_len + 1));
  if (result == NULL)
    _print_error_and_exit(); /* Handle malloc failure */

  /* Initialize the result buffer with '0's */
  _initialize_result_buffer(result, total_len);

  /* Iterate through num2 from right to left (least significant digit first) */
  for (i = len2 - 1; i >= 0; i--)
  {
    int digit2 = num2[i] - '0'; /* Convert char digit to int */
    carry = 0;
    /*
     * current_pos_in_result tracks the starting position in the result buffer
     * for the current partial product. It shifts left with each digit of num2,
     * simulating the shifting of partial products in long multiplication.
     */
    int current_pos_in_result = (total_len - 1) - (len2 - 1 - i);

    /* Iterate through num1 from right to left */
    for (j = len1 - 1; j >= 0; j--)
    {
      int digit1 = num1[j] - '0'; /* Convert char digit to int */
      /*
       * Calculate the product of the two digits, add any existing digit
       * at the current position in the result buffer, and add the carry
       * from the previous multiplication step.
       */
      product = digit1 * digit2 + (result[current_pos_in_result] - '0') + carry;
      carry = product / 10;                                 /* Calculate new carry */
      result[current_pos_in_result] = (product % 10) + '0'; /* Store the current digit */
      current_pos_in_result--;                              /* Move to the left in result buffer */
    }

    /* Add any remaining carry to the next position(s) in the result buffer */
    while (carry > 0)
    {
      /*
       * Add the carry to the digit at current_pos_in_result (which might be '0'
       * if it's beyond the initial length of the partial product).
       */
      product = (result[current_pos_in_result] - '0') + carry;
      result[current_pos_in_result] = (product % 10) + '0';
      carry = product / 10;
      current_pos_in_result--;
    }
  }

  /* Find the first non-zero digit to handle leading zeros in the final result */
  int first_digit = 0;
  while (result[first_digit] == '0' && first_digit < total_len - 1)
  {
    first_digit++;
  }

  /* Print the final result */
  for (i = first_digit; i < total_len; i++)
  {
    _putchar(result[i]);
  }
  _putchar('\n'); /* Print a newline character at the end */

  free(result); /* Free the allocated memory */
}

/**
 * main - Entry point for the infinite multiplication program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on successful execution, 98 on error.
 */
int main(int argc, char *argv[])
{
  char *num1_str;
  char *num2_str;
  int i;

  /* Check for correct number of arguments */
  if (argc != 3)
  {
    _print_error_and_exit();
  }

  num1_str = argv[1];
  num2_str = argv[2];

  /* Validate num1_str: ensure it contains only digits */
  for (i = 0; num1_str[i] != '\0'; i++)
  {
    if (!_is_digit(num1_str[i]))
    {
      _print_error_and_exit();
    }
  }

  /* Validate num2_str: ensure it contains only digits */
  for (i = 0; num2_str[i] != '\0'; i++)
  {
    if (!_is_digit(num2_str[i]))
    {
      _print_error_and_exit();
    }
  }

  /* Handle edge case: if one or both numbers are "0", the result is "0" */
  if ((_strlen(num1_str) == 1 && num1_str[0] == '0') ||
      (_strlen(num2_str) == 1 && num2_str[0] == '0'))
  {
    _putchar('0');
    _putchar('\n');
    return (0);
  }

  /* Perform the multiplication */
  _multiply(num1_str, num2_str);

  return (0);
}
