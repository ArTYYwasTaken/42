/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:10:43 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/02 21:04:24 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	rush_border(int x)
{
	int	width_count;
	int	width_index;

	width_count = x - 2;
	width_index = 0;
	ft_putchar('A');
	while (width_index < width_count)
	{
		ft_putchar('B');
		width_index++;
	}
	if (x > 1)
		ft_putchar('C');
}

void	rush_length(int x, int y, int space_width)
{
	int	current_row;
	int	space_index;
	int	row_count;

	row_count = y - 2;
	current_row = 0;
	while (current_row < row_count)
	{
		ft_putchar('B');
		if (x > 1)
		{
			space_index = 0;
			while (space_index < space_width)
			{
				ft_putchar(' ');
				space_index++;
			}
			ft_putchar('B');
		}
		ft_putchar('\n');
		current_row++;
	}
}

void	rush(int x, int y)
{
	int	space_width;
	int	width_index;

	width_index = 0;
	space_width = x - 2;
	if (x <= 0 || y <= 0)
		return ;
	ft_putchar('A');
	while (width_index < space_width)
	{
		ft_putchar('B');
		width_index++;
	}
	if (x > 1)
		ft_putchar('C');
	ft_putchar('\n');
	if (y > 2)
		rush_length(x, y, space_width);
	if (y > 1)
		rush_border(x);
}
/*
int main()
{
    rush(79, 35);
    return 0;
} */
