/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-randomization_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 05:48:49 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/12 18:29:14 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	poke_rand(t_collectable *col, int y, int x, int *i)
{
		col[*i].x = x;
		col[*i].y = y;
		col[*i].pokemon_type = rand() % NUM_POKE;
		col[*i].frame = 0;
		(*i)++;
}

static void	bolder_rand(t_map *map, int y, int x)
{
	int	rand_num;

	rand_num = rand() % NUM_BOLDERS;
	if (rand_num == 0)
		map->grid[y][x] = '2';
	else
		map->grid[y][x] = '3';
}

static void	randomize_cell(t_map *map, t_collectable *col, int y, int x, int *i)
{
	if (map->grid[y][x] == 'C')
		poke_rand(col, y, x, i);
	if (map->grid[y][x] == '1')
		bolder_rand(map, y, x);
}

void	randomization(t_map *map, t_collectable *col, int *col_count)
{
	static int	seeded;
	int			i;
	int			x;
	int			y;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	i = 0;
	y = 1;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
			randomize_cell(map, col, y, x++, &i);
		y++;
	}
	*col_count = i;
}
