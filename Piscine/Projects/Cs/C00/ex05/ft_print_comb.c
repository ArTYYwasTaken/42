/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:26:30 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/02 15:37:12 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	ft_result(char n1, char n2, char n3)
{
	bool	lastn;

	ft_putchar(n1);
	ft_putchar(n2);
	ft_putchar(n3);
	lastn = (!(n1 == '7' && n2 == '8' && n3 == '9'));
	if (lastn)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0';
	while (n1 <= '7')
	{
		n2 = n1 + 1;
		while (n2 <= '8')
		{
			n3 = n2 + 1;
			while (n3 <= '9')
			{
				ft_result(n1, n2, n3);
				n3++;
			}
			n2++;
		}
		n1++;
	}
}
/*
int main() {
	ft_print_comb();
}*/
