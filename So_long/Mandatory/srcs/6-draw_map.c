/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-draw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 01:12:42 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/29 17:48:50 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	wall_placement(t_image img, t_map *map, int y, int x)
{
	if (x == 0 && y == 0)
		return (img.nw_corner);
	else if (x == map->width - 1 && y == 0)
		return (img.ne_corner);
	else if (y == 0)
		return (img.n_wall);
	else if (y == map->height - 1)
		return (img.s_wall);
	else if (x == 0)
		return (img.w_wall);
	else if (x == map->width - 1)
		return (img.e_wall);
	else
		return (img.bolder);
}

void	draw_sprite(t_game *game, t_sprite sprite, int y, int x)
{
	int	pxl_x;
	int	pxl_y;

	pxl_x = x * PX;
	pxl_y = y * PX;
	mlx_put_image_to_window(game->mlx, game->win, sprite, pxl_x, pxl_y);
}

void	draw_map_row(t_game *game, int y)
{
	int			x;
	t_sprite	sprite;
	char		tile;

	x = 0;
	while (x < game->map->width)
	{
		tile = game->map->grid[y][x];
		if (tile == '1')
			sprite = wall_placement(game->img, game->map, y, x);
		else if (tile == 'E')
			sprite = game->img.exit;
		else if (tile == 'C')
			sprite = game->img.dialga;
		else
			sprite = game->img.floor;
		draw_sprite(game, sprite, y, x);
		x++;
	}
}

int	draw_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		draw_map_row(game, y);
		y++;
	}
	draw_sprite(game, game->img.player, game->map->player_y,
		game->map->player_x);
	return (0);
}
