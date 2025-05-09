/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:48:40 by leramos-          #+#    #+#             */
/*   Updated: 2025/03/18 14:22:36 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*array;
	int	array_size;

	array_size = max - min;
	if (array_size < 1)
	{
		*range = NULL;
		return (0);
	}
	array = malloc(sizeof(int) * array_size);
	if (array == NULL)
		return (-1);
	i = 0;
	while (i < array_size)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (array_size);
}

/* #include <stdio.h>
int	main(void)
{
	int	min = -10;
	int	max = 10;
	int	i = 0;
	int	*range;
	int	size = ft_ultimate_range(&range, min, max);

	i = 0;
	printf("\nRange Size: %d\n", size);
	while (i < size)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
} */