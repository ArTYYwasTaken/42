/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:53:56 by leramos-          #+#    #+#             */
/*   Updated: 2025/03/18 14:47:12 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_total_size(int size, char **strs, char *sep)
{
	int	i;
	int	sum;

	sum = get_str_size(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		sum += get_str_size(strs[i]);
		i++;
	}
	sum++;
	return (sum);
}

void	strlcpy(char *dest, char *src, int *index)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}
}

void	concatenate_strings(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	dest_index;

	i = 0;
	dest_index = 0;
	while (i < size)
	{
		ft_copystr(dest, strs[i], &dest_index);
		if (i < size - 1)
			ft_copystr(dest, sep, &dest_index);
		i++;
	}
	dest[dest_index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;

	if (size == 0)
	{
		dest = malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
	}
	else
	{
		dest = malloc(sizeof(char) * get_total_size(size, strs, sep));
		if (dest == NULL)
			return (NULL);
		concatenate_strings(size, strs, sep, dest);
	}
	return (dest);
}

/* #include <stdio.h>
int	main(void)
{
    char *strs[] = {"Hello", "world", "this", "is", "a", "test"};
	int size = 6;
	char *sep = " ";
	// Hello world this is a test
	// printf("total size: %d\n", get_total_size(size, strs, sep));
	int	i = 0;
	char	*all_together = ft_strjoin(size, strs, sep);

	while (i < size)
	{
		printf("String in the index %d: %s\n", i, strs[i]);
		i++;
	}
	printf("New string: %s\n", all_together);
	free(all_together);
} */