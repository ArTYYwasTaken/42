/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9-key_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 05:41:55 by kemontei            #+#    #+#           */
/*   Updated: 2025/07/30 05:41:55 by kemontei           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_col_exit(t_game *game, int y, int x)
{
	char	*tile;

	tile = &game->map->grid[y][x];
	if (*tile == 'C')
	{
		*tile = '0';
		game->map->col--;
	}
	else if (*tile == 'E')
	{
		if (game->map->col == 0)
			game_won(game);
	}
}

void 	handle_enter(t_game *game, int y, int x)
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

void	key_inputs(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == W || keycode == UP)
		move_up(game);
	else if (keycode == A || keycode == LEFT)
		move_left(game);
	else if (keycode == S || keycode == DOWN)
		move_down(game);
	else if (keycode == D || keycode == RIGHT)
		move_right(game);
	else if (keycode == ENTER)
		handle_enter(game, game->map->player_y, game->map->player_x);
	else if (keycode == ESC)
	{
		game_lost(game);
		exit(EXIT_SUCCESS);
	}
}
