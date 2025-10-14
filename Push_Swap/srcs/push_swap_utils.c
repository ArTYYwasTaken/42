/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:38:27 by kemontei          #+#    #+#             */
/*   Updated: 2025/10/14 19:48:39 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_len(long num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	free_grid(char **grid)
{
	size_t	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i]) 
		free(grid[i++]);
	free (grid);
}

void	clean_push(t_stack **stack_a, t_stack **stack_b, char **args)
{
	if (stack_a && *stack_a)
		clear_stack(stack_a);
	if (stack_b && *stack_b)
		clear_stack(stack_b);
	if (args)
		free_grid(args);
}

void	print_error(void)
{
	char	*header;

	header = "\033[1;31m🛑Error\033[0m\n";
	ft_putstr_fd(header, 2);
}

long	ft_atol(const char *str)
{
	long	num;
	long	sign;
	size_t	i;

	if (!str)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit((int)str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
