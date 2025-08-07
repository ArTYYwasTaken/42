/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_functions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:51:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/05 17:09:50 by kemontei         ###   ########.fr       */
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
	if (img->W_wall)
		mlx_destroy_image(mlx, img->W_wall);
	if (img->S_wall)
		mlx_destroy_image(mlx, img->S_wall);
	if (img->E_wall)
		mlx_destroy_image(mlx, img->E_wall);
	if (img->N_wall)
		mlx_destroy_image(mlx, img->N_wall);
	if (img->NW_corner)
		mlx_destroy_image(mlx, img->NW_corner);
	if (img->NE_corner)
		mlx_destroy_image(mlx, img->NE_corner);
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
	if (!player || !mlx)
		return ;
	if (player->down0)
		mlx_destroy_image(mlx, player->down0);
	if (player->down1)
		mlx_destroy_image(mlx, player->down1);
	if (player->down2)
		mlx_destroy_image(mlx, player->down2);
	if (player->left0)
		mlx_destroy_image(mlx, player->left0);
	if (player->left1)
		mlx_destroy_image(mlx, player->left1);
	if (player->left2)
		mlx_destroy_image(mlx, player->left2);
}

void	clean_player2(t_player *player, void *mlx)
{
	if (player->right0)
		mlx_destroy_image(mlx, player->right0);
	if (player->right1)
		mlx_destroy_image(mlx, player->right1);
	if (player->right2)
		mlx_destroy_image(mlx, player->right2);
	if (player->up0)
		mlx_destroy_image(mlx, player->up0);
	if (player->up1)
		mlx_destroy_image(mlx, player->up1);
	if (player->up2)
		mlx_destroy_image(mlx, player->up2);
}
