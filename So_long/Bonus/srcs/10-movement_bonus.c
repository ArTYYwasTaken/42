/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10-movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 04:16:50 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/11 18:29:04 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	move_animation_up(game, y, x);
	game->map->player_y = y;
	game->map->player_x = x;
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
    move_animation_down(game, y, x);
	game->map->player_y = y;
	game->map->player_x = x;
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
    move_animation_left(game, y, x);
	game->map->player_y = y;
	game->map->player_x = x;
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
    move_animation_right(game, y, x);
	game->map->player_y = y;
	game->map->player_x = x;
	game->map->last_input = 'E';
}
