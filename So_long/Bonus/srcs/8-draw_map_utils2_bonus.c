/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-draw_map_utils2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 02:35:50 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 17:42:41 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	find_enemy_index(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->enemies)
	{
		if (game->enemies[i].x == x && game->enemies[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

t_sprite	enemy_tiles(t_game *game, t_enemy *enemy, int y, int x)
{
	int	enemy_type;
	int	i;

	i = find_enemy_index(game, x, y);
	if (i != -1)
	{
		enemy_type = enemy[i].enemy_type;
		if (enemy_type == 0)
			return (game->img.colress.frames[enemy[i].frame]);
		else if (enemy_type == 1)
			return (game->img.ghetsis.frames[enemy[i].frame]);
		else if (enemy_type == 2)
			return (game->img.n.frames[enemy[i].frame]);
		else if (enemy_type == 3)
			return (game->img.f_plasma.frames[enemy[i].frame]);
		else if (enemy_type == 4)
			return (game->img.m_plasma.frames[enemy[i].frame]);
		else if (enemy_type == 5)
			return (game->img.scientist.frames[enemy[i].frame]);
	}
	return (game->img.floor);
}
