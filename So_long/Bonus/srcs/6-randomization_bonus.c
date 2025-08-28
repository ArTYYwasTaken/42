/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-randomization_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 05:48:49 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/28 17:59:28 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	poke_rand(t_collectable *collectable, int y, int x, int *i)
{
	collectable[*i].x = x;
	collectable[*i].y = y;
	collectable[*i].pokemon_type = rand() % NUM_POKE;
	collectable[*i].frame = 0;
	(*i)++;
}

static void	enemy_rand(t_enemy *enemy, int y, int x, int *i)
{
	enemy[*i].x = x;
	enemy[*i].y = y;
	enemy[*i].enemy_type = rand() % NUM_ENEMY;
	enemy[*i].frame = 0;
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

static void	randomize_cell(t_game *game, int y, int x, ...)
{
	va_list	args;
	int		*col_i;
	int		*enem_i;

	va_start(args, x);
	col_i = va_arg(args, int *);
	enem_i = va_arg(args, int *);
	if (game->map->grid[y][x] == 'C')
		poke_rand(game->collectables, y, x, col_i);
	if (game->map->grid[y][x] == 'X')
		enemy_rand(game->enemies, y, x, enem_i);
	if (game->map->grid[y][x] == '1')
		bolder_rand(game->map, y, x);
	va_end(args);
}

void	randomization(t_game *game, t_map *map, int *collectable_count,
						int *enemy_count)
{
	static int	seeded;
	int			col_i;
	int			enem_i;
	int			x;
	int			y;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	col_i = 0;
	enem_i = 0;
	y = 1;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
			randomize_cell(game, y, x++, &col_i, &enem_i);
		y++;
	}
	*collectable_count = col_i;
	*enemy_count = enem_i;
}
