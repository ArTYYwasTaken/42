/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prshrest <prshrest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:33:45 by prshrest          #+#    #+#             */
/*   Updated: 2025/03/13 06:58:48 by prshrest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = argc - 1;
	while (i >= 1)
	{
		j = 0;
		while (argv[i][j])
		{
			write (1, &argv[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i--;
	}
	return (0);
}
