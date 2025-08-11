/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-draw_map_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 03:25:04 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/11 19:22:52 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_sprite	wall_placement(t_image img,t_map *map, int y, int x)
{
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

t_sprite	poke_tiles(t_game *game, t_collectable *collectable, int y, int x)
{
	int	poke_type;
	int	i;

	i = find_pokemon_index(game, x, y);
	if (i != -1)
	{
		poke_type = collectable[i].pokemon_type;
		if (poke_type == 0)
			return (game->img.dialga.frames[collectable[i].frame]);
		else if (poke_type == 1)
			return (game->img.palkia.frames[collectable[i].frame]);
		else if (poke_type == 2)
			return (game->img.giratina.frames[collectable[i].frame]);
	}
	return (game->img.floor);
}