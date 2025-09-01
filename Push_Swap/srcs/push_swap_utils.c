/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:38:27 by kemontei          #+#    #+#             */
/*   Updated: 2025/09/01 18:32:53 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_error(char *msg)
{
	char	*header;

	header = "\033[1;31m🛑Error\033[0m\n";
	ft_putstr_fd(header, 2);
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
}

int	ft_atol(const char *str)
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