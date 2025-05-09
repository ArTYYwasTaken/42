/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:13:11 by migusant          #+#    #+#             */
/*   Updated: 2025/03/15 18:23:09 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr_temp;
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr_temp = (int *)malloc(size * sizeof(int));
	if (!arr_temp)
		return (-1);
	i = 0;
	while (min < max)
	{
		arr_temp[i] = min;
		min++;
		i++;
	}
	*range = arr_temp;
	return (i);
}

/* int	main()
{
	int	i;
	int	min;
	int	max;
	int	**arr1;
	int	*arr2;
	int	size;

	i = 0;
	min = -100;
	max = 100;
	arr1 = &arr2;
	size = max - min;
	printf("%d \n", ft_ultimate_range(arr1, min, max));
	while (i < size - 1)
	{
		printf("%d ", arr2[i]);
		i++;
	}
	printf("%d\n", arr2[i]);
	free(arr2);
	return 0;
} */
