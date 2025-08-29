/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:51:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/29 17:50:24 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	clean_images(t_game *game, void *mlx)
{
	if (!game || !mlx)
		return ;
	if (game->img.floor)
		mlx_destroy_image(mlx, game->img.floor);
	if (game->img.exit)
		mlx_destroy_image(mlx, game->img.exit);
	if (game->img.w_wall)
		mlx_destroy_image(mlx, game->img.w_wall);
	if (game->img.s_wall)
		mlx_destroy_image(mlx, game->img.s_wall);
	if (game->img.e_wall)
		mlx_destroy_image(mlx, game->img.e_wall);
	if (game->img.n_wall)
		mlx_destroy_image(mlx, game->img.n_wall);
	if (game->img.nw_corner)
		mlx_destroy_image(mlx, game->img.nw_corner);
	if (game->img.ne_corner)
		mlx_destroy_image(mlx, game->img.ne_corner);
	if (game->img.bolder)
		mlx_destroy_image(mlx, game->img.bolder);
	if (game->img.dialga)
		mlx_destroy_image(mlx, game->img.dialga);
	if (game->img.player)
		mlx_destroy_image(mlx, game->img.player);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	clean_images(game, game->mlx);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		(mlx_destroy_display(game->mlx), free(game->mlx));
	if (game->map)
		clean_map(game->map);
	free(game);
	exit (0);
}

int	finish_game(t_game *game)
{
	free_game(game);
	return (0);
}
