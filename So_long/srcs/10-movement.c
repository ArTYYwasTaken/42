/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9-movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 04:16:50 by kemontei            #+#    #+#           */
/*   Updated: 2025/07/30 04:16:50 by kemontei           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_game *game)
{
    int y;
    int x;

    y = game->map->player_y;
    x = game->map->player_x;
    if (map->grid[y - 1][x] == 'C' || map->grid[y - 1][x] == 'E'
	    || map->grid[y - 1][x] == '1')
    {
		game->map->moves++;
        game->map->grid[y][x] = '0'
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
    if (map->grid[y + 1][x] == 'C' || map->grid[y + 1][x] == 'E'
	    || map->grid[y + 1][x] == '1')
    {
		game->map->moves++;
        game->map->grid[y][x] = '0'
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
    if (map->grid[y][x - 1] == 'C' || map->grid[y][x - 1] == 'E'
	|| map->grid[y][x - 1] == '1')
    {
		game->map->moves++;
        game->map->grid[y][x] = '0'
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
    if (map->grid[y][x + 1] == 'C' || map->grid[y][x + 1] == 'E'
	|| map->grid[y][x + 1] == '1')
    {
		game->map->moves++;
        game->map->grid[y][x] = '0'
        x++;
        game->map->grid[y][x] = 'P';
		print_moves(game);
    }
    move_animation_right(game, y, x);
	game->map->player_y = y;
	game->map->player_x = x;
	game->map->last_input = 'E';
}
