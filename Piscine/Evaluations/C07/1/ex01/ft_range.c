/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:30:42 by migusant          #+#    #+#             */
/*   Updated: 2025/03/15 17:40:10 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	size;

	size = max - min;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

/* int	main()
{
	int	i;
	int	min;
	int	max;
	int	*arr;
	int	size;

	i = 0;
	min = -100;
	max = 100;
	size = max - min;

	arr = ft_range(min, max);
	while (i < size - 1)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("%d", arr[i]);
	printf("\n");
	free(arr);
	return 0;
} */
