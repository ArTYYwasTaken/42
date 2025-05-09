/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:17:52 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/04 20:17:55 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		temp;
	int		i;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}
// int main()
// {
// 	int x[] = {1, 2, 3, 4, 5};
// 	int count;

// 	count = 5;
// 	ft_rev_int_tab(x, count);
// 	printf("Numero inverso: %d\n", x[0]);
// }