/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9-key_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 05:41:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/12 18:36:18 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	remove_collectable(t_game *game, int x, int y)
{
	int	i;
	int	last;

	i = 0;
	last = game->map->col - 1;
	while (i <= last)
	{
		if (game->collectables[i].x == x && game->collectables[i].y == y)
		{
			if (i != last)
				game->collectables[i] = game->collectables[last];
			game->map->col--;
			break;
		}
		i++;
	}
}

static void	check_col_exit(t_game *game, int y, int x)
{
	char	*tile;

	tile = &game->map->grid[y][x];
	if (*tile == 'C')
	{
		*tile = '0';
		remove_collectable(game, x ,y);
	}
	else if (*tile == 'E')
	{
		if (game->map->col == 0)
			game_won(game);
	}
}

static void 	handle_enter(t_game *game, int y, int x)
{
	if (game->map->last_input == 'N')
		check_col_exit(game, y - 1, x);
	else if (game->map->last_input == 'S')
		check_col_exit(game, y + 1, x);
	else if (game->map->last_input == 'W')
		check_col_exit(game, y, x - 1);
	else if (game->map->last_input == 'E')
		check_col_exit(game, y, x + 1);
}

int	key_inputs(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		move_up(game);
	else if (keycode == XK_a || keycode == XK_Left)
		move_left(game);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(game);
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(game);
	else if (keycode == XK_Return || keycode == XK_space)
		handle_enter(game, game->map->player_y, game->map->player_x);
	else if (keycode == XK_Escape)
	{
		game_lost(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
