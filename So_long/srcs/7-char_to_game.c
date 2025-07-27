/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 03:25:04 by kemontei            #+#    #+#           */
/*   Updated: 2025/07/26 03:25:04 by kemontei           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	wall_placement(t_image img,t_map *map, int y, int x)
{
	t_sprite	wall;

	if(x == 0 && y == 0)
		return (img.NW_corner);
	else if (x == map->width - 1 && y == 0)
		return (img.NE_corner);
	else if (y == 0)
		return (img.N_wall);
	else if (y == map->height - 1)
		return (img.S_wall);
	else if (x == 0)
		return (img.W_wall);
	else if (x == map->width - 1)
		return (img.E_wall);
	else if (map->grid[y][x] == '2')
		return (img.bolder_1);
	else if (map->grid[y][x] == '3')
		return (img.bolder_2);
	else
		return (img.bolder_1);
}

void	draw_sprite(t_game *game, t_sprite sprite, int y, int x)
{
	int	pxl_x;
	int	pxl_y;

	pxl_x = x * PX;
	pxl_y = y * PX;
	mlx_put_image_to_window(game->mlx, game->win, sprite, pxl_x, pxl_y);
}

int find_pokemon_index(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->col)
	{
		if (game->collectables[i].x == x && game->collectables[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

t_sprite	poke_tiles(t_game *game, t_collectable *col, int y, int x)
{
	int			poke_type;
	int			i;

	i = find_pokemon_index(game, x, y);
	if (i != -1)
	{
		poke_type = col[i].pokemon_type;
		if (poke_type == 0)
			return (game->img.dialga.frames[col[i].frame]);
		else if (poke_type == 1)
			return (game->img.palkia.frames[col[i].frame]);
		else if (poke_type == 2)
			return (game->img.giratina.frames[col[i].frame]);
	}
	return (game->img.floor);
}

void draw_map_row(t_game *game, t_collectable *col, int y)
{
	int			x;
	t_sprite	sprite;
	char		tile;

	x = 0;
	while (x < game->map->width)
	{
		tile = game->map->grid[y][x];
		if (tile == '1' || tile == '2' || tile == '3')
			sprite = wall_placement(game->img, game->map, x, y);
		else if (tile == 'P')
			sprite = game->player.Down0;
		else if (tile == 'E')
			sprite = game->img.exit;
		else if (tile == 'C')
			sprite = poke_tiles(game, col, x, y);
		else
			sprite = game->img.floor;
		draw_sprite(game, sprite, x, y);
		x++;
	}
}

void	draw_map(t_game *game, t_collectable *col)
{
	int y;

	y = 0;
	while (y < game->map->height)
	{
		draw_map_row(game, col, y, col_count);
		y++;
	}
}
