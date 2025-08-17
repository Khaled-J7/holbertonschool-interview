#include "substring.h"
#include <string.h>

/**
 * find_substring - Finds all possible substrings containing a list of words.
 * @s: The string to scan.
 * @words: The array of words all substrings must be a concatenation of.
 * @nb_words: The number of elements in the array `words`.
 * @n: Holds the address at which to store the number of elements in the
 * returned array.
 *
 * Return: An allocated array storing each index in `s` at which a substring
 * was found. If no solution is found, NULL is returned.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, word_len, concat_len, i, j, k, count;
	int *indices, *seen_words;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	concat_len = nb_words * word_len;
	*n = 0;

	if (s_len < concat_len)
		return (NULL);

	indices = malloc(sizeof(int) * s_len);
	if (!indices)
		return (NULL);
	seen_words = malloc(sizeof(int) * nb_words);
	if (!seen_words)
	{
		free(indices);
		return (NULL);
	}
	for (i = 0, count = 0; i <= s_len - concat_len; i++)
	{
		memset(seen_words, 0, sizeof(int) * nb_words);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (!seen_words[k] &&
				    strncmp(s + i + (j * word_len), words[k], word_len) == 0)
				{
					seen_words[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			indices[count++] = i;
	}
	free(seen_words);
	*n = count;
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
