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

#include "so_long.h"

// void	move_resume(t_map *map, int y, int x, int key)
// {
// 	if (key = W || key == UP)
// 		y -= 1;
// 	if (key = S || key == DOWN)
// 		y += 1;
// 	if (key = A || key == LEFT)
// 		x -= 1;
// 	if (key = W || key == RIGHT)
// 		x += 1;
// 	map->moves++;
// }

void	check_col_exit(t_game *game, char tile)
{
	if (tile == 'C')
	{
		tile == '0';
		game->map->col--;
	}
	if (tile == 'E')
	{
		if (game->map->col == 0)
			return (game_won(game));
		else
			return ;	
	}
}

void 	handle_enter(t_game *game, int y, int x)
{
	if (game->map->LastInput == 'N')
		check_col_exit(game, game->map->grid[y - 1][x]);
	if (game->map->LastInput == 'S')
		check_col_exit(game, game->map->grid[y + 1][x]);
	if (game->map->LastInput == 'W')
		check_col_exit(game, game->map->grid[y][x - 1]);
	if (game->map->LastInput == 'E')
		check_col_exit(game, game->map->grid[y][x + 1]);
	else
		return ;
}

void	key_inputs(int keycode, void *param)
{
	t_game *game;

	game = param;
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	if (keycode == ENTER)
		handle_enter(game, game->map->player_y, game->map->player_x);
	if (keycode == ESC)
	{
		game_lost(game);
		exit(EXIT_SUCCESS);
	}
}
