/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:30:09 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/14 14:36:36 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	print_error(char *msg)
{
	char	*header;

	header = "\033[1;31m🛑Error\033[0m\n";
	write(2, header, ft_strlen(header));
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->map->moves);
	ft_printf("I would say about %s moves\n", moves);
	mlx_string_put(game->mlx, game->win, 500, 600, 0x000000, moves);
	free (moves);
}
