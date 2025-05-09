/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:43:33 by migusant          #+#    #+#             */
/*   Updated: 2025/03/17 10:27:02 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_char_in_string(char ch, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ch == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words_in_string(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_char_in_string(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !(ft_is_char_in_string(str[i], charset)))
			i++;
	}
	return (count);
}

int	ft_find_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(ft_is_char_in_string(str[i], charset)))
		i++;
	return (i);
}

char	*ft_store_word(char *str, char *charset)
{
	int		i;
	int		wordlen;
	char	*arr;

	i = 0;
	wordlen = ft_find_word_len(str, charset);
	arr = (char *)malloc((wordlen + 1) * sizeof(char));
	while (str[i] != '\0' && !(ft_is_char_in_string(str[i], charset)))
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;
	char	**arr;

	i = 0;
	j = 0;
	count = ft_count_words_in_string(str, charset);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	while (str[i] != '\0' && j < count)
	{
		while (str[i] != '\0' && ft_is_char_in_string(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			arr[j] = ft_store_word((str + i), charset);
			j++;
		}
		while (str[i] != '\0' && !(ft_is_char_in_string(str[i], charset)))
			i++;
	}
	arr[j] = 0;
	return (arr);
}

int	main()
{
	int		i;
	char	**strs;
	char	*str;
	char	*sep;

	i = 0;
	sep = "!#$&/(";
	str = "!Hello#World$this&is/a(test.";
	strs = ft_split(str, sep);
	while (strs[i] != 0)
	{
		printf("%s\n", strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
	return 0;
}
