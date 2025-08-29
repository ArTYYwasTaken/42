/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:30:09 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/29 17:13:52 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	print_error(char *msg)
{
	char	*header;

	header = "\033[1;31m🛑Error\033[0m\n";
	ft_putstr_fd(header, 2);
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
}

static void	number_on_screen(t_game *game, char *moves, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			mlx_string_put(game->mlx, game->win, x + i, y + j, 0x000000, moves);
			j++;
		}
		i++;
	}
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, moves);
}

void	print_moves_screen(t_game *game)
{
	char	*moves;
	int		pxl_x;
	int		pxl_y;
	int		text_width;
	int		center_x;

	if (!game->win)
		return ;
	moves = ft_itoa(game->map->moves);
	text_width = ft_strlen(moves) * 6;
	center_x = 1 * PX - 63;
	pxl_x = center_x - (text_width / 2);
	pxl_y = (game->map->height - 1) * PX + 41;
	number_on_screen(game, moves, pxl_x, pxl_y);
	free (moves);
}

void	print_moves_terminal(t_game *game)
{
	char	*moves;

	if (!game->win)
		return ;
	moves = ft_itoa(game->map->moves);
	if (game->map->moves == 1)
		ft_printf("I would say about %s move\n", moves);
	else
		ft_printf("I would say about %s moves\n", moves);
	free (moves);
}
