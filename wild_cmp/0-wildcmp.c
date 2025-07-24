#include "holberton.h"

/**
 * wildcmp - Compares two strings and returns 1 if they can be considered
 * identical, otherwise returns 0. s2 can contain the special character *.
 * @s1: The first string (without wildcards).
 * @s2: The second string (can contain wildcards).
 *
 * Return: 1 if the strings are identical, 0 otherwise.
 */
int wildcmp(char * s1, char * s2) {
  /* If we reach the end of both strings, they are identical. */
  if ( * s1 == '\0' && * s2 == '\0')
    return (1);

  /* If the characters match, continue with the next characters. */
  if ( * s1 == * s2)
    return (wildcmp(s1 + 1, s2 + 1));

  /* If s2 has a wildcard '*' */
  if ( * s2 == '*') {
    /* If the next char in s2 is also '*', we can skip the current one. */
    if ( * (s2 + 1) == '*')
      return (wildcmp(s1, s2 + 1));

    /*
     * The '*' can either match an empty string or match one or more
     * characters.
     *
     * Case 1: '*' matches an empty string.
     * We check if the rest of s1 matches the rest of s2 (from s2 + 1).
     *
     * Case 2: '*' matches one character in s1.
     * We check if the rest of s1 (from s1 + 1) matches s2 (from '*').
     *
     * If s1 is at its end, the '*' must match an empty string.
     */
    if ( * s1 == '\0')
      return (wildcmp(s1, s2 + 1));

    /*
     * The core recursive step for the wildcard.
     * Try both possibilities:
     * 1. wildcmp(s1, s2 + 1): '*' matches an empty string.
     * 2. wildcmp(s1 + 1, s2): '*' matches the current char in s1.
     * If either is true, we have a match.
     */
    return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
  }

  /* If none of the above, the strings do not match. */
  return (0);
}
