/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:18:07 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/06 14:18:09 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// void	ft_print_list(int *tab, int num)
// {
// 	int	i;

// 	i = 0;
// 	while (i < num){
// 		printf("%i ", tab[i]);
// 		i++;}
// 	printf("\n");
// }

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
// int main()
// {
// 	int x[] = {25, 5, 15, 10, 1, 20};
// 	int n = 6;

// 	ft_print_list(x, n);
// 	ft_sort_int_tab(x, n);
// 	ft_print_list(x, n);
// 	return (0);
// }
