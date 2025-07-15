/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:22:44 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/14 17:25:06 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mv_exit(t_map *map)
{
	int	y;
	int	x;
	int	count;

	y = 1;
	count = 0;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] == 'E')
			{
				count++;
				map->exit_x = x;
				map->exit_y = y;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	ft_printf("--//exit/--\nx:%d\ty:%d\n\n", map->exit_x, map->exit_y);
	return (1);
}

int	mv_player(t_map *map)
{
	int	y;
	int	x;
	int	count;

	y = 1;
	count = 0;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] == 'P')
			{
				count++;
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	ft_printf("--//player/--\nx:%d\ty:%d\n", map->player_x, map->player_y);
	return (1);
}

int	mv_characters(t_map *map)
{
	int	y;
	int	x;

	y = 1;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] != '1'
				&& map->grid[y][x] != '0'
				&& map->grid[y][x] != 'C'
				&& map->grid[y][x] != 'E'
				&& map->grid[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	mv_borders(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	map_validation(t_map *map)
{
	if (!mv_borders(map))
		return (perror("Failed borders validation"), 0);
	if (!mv_characters(map))
		return (perror("Invalid characters found"), 0);
	if (!mv_player(map))
		return (perror("Failed player requirement"), 0);
	if (!mv_exit(map))
		return (perror("Failed exit requirement"), 0);
	if (!mv_collectables(map))
		return (perror("Failed to meet collectables requirement"), 0);
	if (!mv_path(map))
		return (perror("Invalid path"), 0);
	return (1);
}
