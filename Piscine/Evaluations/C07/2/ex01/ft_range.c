/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:30:56 by leramos-          #+#    #+#             */
/*   Updated: 2025/03/18 13:33:14 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;
	int	array_size;

	array_size = max - min;
	if (array_size < 1)
		return (NULL);
	array = malloc(sizeof(int) * array_size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

#include <stdio.h>
int	main(void)
{
	int	min = -10;
	int	max = 10;
	int	i = 0;
	int	*range = ft_range(min, max);
	int	size = max - min;
	while (i < size)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
}