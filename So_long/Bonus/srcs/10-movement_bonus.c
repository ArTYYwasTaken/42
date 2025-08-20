/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10-movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 04:16:50 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/12 18:37:21 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    move_animation(t_game *game, t_direction direction, int y, int x)
{
		if (game->player.direction != direction)
			game->player.player_frame = 0;
		game->map->player_y = y;
		game->player.direction = direction;
		game->map->player_x = x;
	}

void    move_up(t_game *game)
{
	int y;
	int x;

	y = game->map->player_y;
	x = game->map->player_x;
	if (game->map->grid[y - 1][x] == '0')
	{
		game->map->moves++;
		game->map->grid[y][x] = '0';
		y--;
		game->map->grid[y][x] = 'P';
		print_moves(game);
	}
	move_animation(game, UP, y, x);
	game->map->last_input = 'N';
}

void    move_down(t_game *game)
{
	int y;
	int x;

	y = game->map->player_y;
	x = game->map->player_x;
	if (game->map->grid[y + 1][x] == '0')
	{
		game->map->moves++;
		game->map->grid[y][x] = '0';
		y++;
		game->map->grid[y][x] = 'P';
		print_moves(game);
	}
	move_animation(game, DOWN, y, x);
	game->map->last_input = 'S';
}

void    move_left(t_game *game)
{
	int y;
	int x;

	y = game->map->player_y;
	x = game->map->player_x;
	if (game->map->grid[y][x - 1] == '0')
	{
		game->map->moves++;
		game->map->grid[y][x] = '0';
		x--;
		game->map->grid[y][x] = 'P';
		print_moves(game);
	}
	move_animation(game, LEFT, y, x);
	game->map->last_input = 'W';
}

void    move_right(t_game *game)
{
	int y;
	int x;

	y = game->map->player_y;
	x = game->map->player_x;
	if (game->map->grid[y][x + 1] == '0')
	{
		game->map->moves++;
		game->map->grid[y][x] = '0';
		x++;
		game->map->grid[y][x] = 'P';
		print_moves(game);
	}
	move_animation(game, RIGHT, y, x);
	game->map->last_input = 'E';
}
