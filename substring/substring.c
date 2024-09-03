#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_substring - Finds all the possible substrings containing all the words
 * @s: The string to search
 * @words: The words to find
 * @nb_words: The number of words
 * @n: A pointer to the number of elements in the returned array
 *
 * Return: An array with the indices of the substrings, or NULL on failure
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len, *word_freq, *result,
result_count = 0, i, j, k;
	char *word;
	int *temp_freq;

	if (!s || !words || nb_words <= 0 || !n)
		return (NULL);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);
	if (s_len < total_len)
		return (NULL);
	word_freq = calloc(nb_words, sizeof(int));
	result = malloc(s_len * sizeof(int));
	for (i = 0; i < nb_words; i++)
		for (j = 0; j < nb_words; j++)
			word_freq[i] += strcmp(words[i], words[j]) == 0;
	for (i = 0; i <= s_len - total_len; i++)
	{
		temp_freq = malloc(nb_words * sizeof(int));
		memcpy(temp_freq, word_freq, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			word = strndup(s + i + j * word_len, word_len);
			for (k = 0; k < nb_words; k++)
				if (strcmp(word, words[k]) == 0 && temp_freq[k]-- > 0)
					break;
			free(word);
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			result[result_count++] = i;
		free(temp_freq);
	}
	*n = result_count;
	free(word_freq);
	return (result_count ? result : (free(result), NULL));
}

