/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_free_game_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 05:26:01 by marvin            #+#    #+#             */
/*   Updated: 2025/08/12 18:07:30 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	if (map->grid)
	{
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	clean_images(&game->img, game->mlx);
	clean_player(&game->player, game->mlx);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->collectables)
		free(game->collectables);
	if (game->map)
		clean_map(game->map);
	free(game);
	exit(0);
}

int	finish_game(t_game *game)
{
	free_game(game);
	return (0);
}