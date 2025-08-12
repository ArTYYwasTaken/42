/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_functions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:51:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/12 19:04:05 by kemontei         ###   ########.fr       */
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

void	clean_pokeframes(t_animated_sprite *pokemon, int frame)
{
	int	i;

	i = 0;
	if (!pokemon || !pokemon->frames)
		return ;
	while (i < frame)
		free(pokemon->frames[i++]);
	free(pokemon->frames);
	pokemon->frames = NULL;
}

void	clean_images(t_image *img, void *mlx)
{
	if (!img || !mlx)
		return ;
	if (img->floor)
		mlx_destroy_image(mlx, img->floor);
	if (img->exit)
		mlx_destroy_image(mlx, img->exit);
	if (img->w_wall)
		mlx_destroy_image(mlx, img->w_wall);
	if (img->s_wall)
		mlx_destroy_image(mlx, img->s_wall);
	if (img->e_wall)
		mlx_destroy_image(mlx, img->e_wall);
	if (img->n_wall)
		mlx_destroy_image(mlx, img->n_wall);
	if (img->nw_corner)
		mlx_destroy_image(mlx, img->nw_corner);
	if (img->ne_corner)
		mlx_destroy_image(mlx, img->ne_corner);
	if (img->bolder_1)
		mlx_destroy_image(mlx, img->bolder_1);
	if (img->bolder_2)
		mlx_destroy_image(mlx, img->bolder_2);
	clean_pokeframes(&img->dialga, img->dialga.frame_count);
	clean_pokeframes(&img->palkia, img->palkia.frame_count);
	clean_pokeframes(&img->giratina, img->giratina.frame_count);
}

void	clean_player(t_player *player, void *mlx)
{
	int x;
	int y;
	
	if (!player || !mlx)
		return ;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while(x < 4)
			mlx_destroy_image(mlx, player->sprites[y][x++]);
		y++;
	}
}
