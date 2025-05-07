/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:15:46 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/07 16:19:49 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*allocate_word(char const *s, char c, size_t *index)
{
	size_t	start;
	size_t	len;
	char	*word;

	start = *index;
	len = 0;
	while (s[*index] && s[*index] != c)
	{
		(*index)++;
		len++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = s[start + len];
	return (word);
}

static void	free_memory(char **words, size_t i)
{
	while (i--)
		free(words[i]);
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_count;
	size_t	i;
	size_t	index;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	index = 0;
	while (i < word_count)
	{
		while (s[index] == c)
			index++;
		words[i] = allocate_word(s, c, &index);
		if (!words[i])
			return (free_memory(words, i), NULL);
		i++;
	}
	words[i] = NULL;
	return (words);
}
