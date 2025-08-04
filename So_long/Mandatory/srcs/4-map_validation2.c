/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:48:14 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/14 17:25:10 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mv_collectables(t_map *map)
{
	int	y;
	int	x;
	int	collectables;
	
	y = 1;
	collectables = 0;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] == 'C')
				collectables++;
			x++;
		}
		y++;
	}
	map->col = collectables;
	if (collectables < 1)
		return (0);
	return (collectables);
}

int mv_floodfill(t_map *map, int x, int y, int collectables)
{
	static int	col;
	static int	exit;

	if (map->grid[y][x] == '1')
		return (0);
	if (map->grid[y][x] == 'C')
		col++;
	if (map->grid[y][x] == 'E')
		exit++;
	map->grid[y][x] = '1';
	mv_floodfill(map, x + 1, y, collectables);
	mv_floodfill(map, x - 1, y, collectables);
	mv_floodfill(map, x, y + 1, collectables);
	mv_floodfill(map, x, y - 1, collectables);
	if (exit == 1 && col == collectables)
		return (1);
	return (0);
}

int mv_path(t_map *map)
{
	t_map	*mapdup;
	int		y;
	int		floodfill;

	mapdup = malloc(sizeof(t_map));
	if (!mapdup)
		return (print_error("Failed to allocate mapdup"), 0);
	mapdup->grid = malloc((map->height + 1) * sizeof(char *));
	if (!mapdup->grid)
		return (print_error("Failed to allocate mapdup grid"), free(mapdup), 0);
	mapdup->grid[map->height] = NULL;
	y = 0;
	while (y < map->height)
	{
		mapdup->grid[y] = ft_strdup(map->grid[y]);
		y++;
	}
	mapdup->col = map->col;
	mapdup->player_x = map->player_x;
	mapdup->player_y = map->player_y;
	floodfill = mv_floodfill(mapdup, mapdup->player_x, mapdup->player_y,
				mapdup->col);
	return (clean_map(mapdup), floodfill);
}
