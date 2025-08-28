/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_functions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:51:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/28 19:14:48 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_pokeframes(t_animated_sprite *pokemon, int frame, void *mlx)
{
	int	i;

	i = 0;
	if (!pokemon || !mlx || !pokemon->frames)
		return ;
	while (i < frame)
		mlx_destroy_image(mlx, pokemon->frames[i++]);
	free(pokemon->frames);
	pokemon->frames = NULL;
}

void	clean_enemyframes(t_animated_sprite *enemy, int frame, void *mlx)
{
	int	i;

	i = 0;
	if (!enemy || !mlx || !enemy->frames)
		return ;
	while (i < frame)
		mlx_destroy_image(mlx, enemy->frames[i++]);
	free(enemy->frames);
	enemy->frames = NULL;
}

void	clean_worldbuilding(t_image *img, void *mlx)
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
	if (img->gameboy)
		mlx_destroy_image(mlx, img->gameboy);
}

void	clean_images(t_image *img, void *mlx)
{
	if (!img || !mlx)
		return ;
	clean_worldbuilding(img, mlx);
	clean_pokeframes(&img->dialga, img->dialga.frame_count, mlx);
	clean_pokeframes(&img->palkia, img->palkia.frame_count, mlx);
	clean_pokeframes(&img->giratina, img->giratina.frame_count, mlx);
	clean_enemyframes(&img->colress, img->colress.frame_count, mlx);
	clean_enemyframes(&img->ghetsis, img->ghetsis.frame_count, mlx);
	clean_enemyframes(&img->n, img->n.frame_count, mlx);
	clean_enemyframes(&img->f_plasma, img->f_plasma.frame_count, mlx);
	clean_enemyframes(&img->m_plasma, img->m_plasma.frame_count, mlx);
	clean_enemyframes(&img->scientist, img->scientist.frame_count, mlx);
}

void	clean_player(t_player *player, void *mlx)
{
	int	x;
	int	y;

	if (!player || !mlx)
		return ;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (player->sprites[y][x])
				mlx_destroy_image(mlx, player->sprites[y][x]);
			x++;
		}
		y++;
	}
}
