#include "regex.h"

/**
 * regex_match - Checks if a given pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	int match = 0;

	/* Base case: If both are at the end, it's a match */
	if (*str == '\0' && *pattern == '\0')
		return (1);

	/* Check for a match of the current characters */
	match = (*str != '\0' && (*str == *pattern || *pattern == '.'));

	/* Handle the '*' wildcard */
	if (*(pattern + 1) == '*')
	{
		/*
		 * Two possibilities for '*':
		 * 1. It matches zero occurrences of the preceding character.
		 * In this case, we can skip the character and the '*' in the pattern.
		 * 2. It matches one or more occurrences.
		 * This is only possible if the current characters match.
		 *
		 * We return true if either possibility leads to a full match.
		 */
		return (regex_match(str, pattern + 2) ||
			(match && regex_match(str + 1, pattern)));
	}

	/* If no '*', proceed with a simple character match */
	if (match)
	{
		return (regex_match(str + 1, pattern + 1));
	}

	/* If no match and no special characters, it's a failure */
	return (0);
}
