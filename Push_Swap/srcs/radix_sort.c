/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:13:16 by marvin            #+#    #+#             */
/*   Updated: 2025/09/17 18:28:30 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	index;
	int	i;
	int	j;

	i = 0;
	while (!stack_sorted(*stack_a))
	{
		j = 0;
		while (j < size)
		{
			index = (*stack_a)->index;
			if (((index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
