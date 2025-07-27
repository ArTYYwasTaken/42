/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:51:28 by kemontei            #+#    #+#           */
/*   Updated: 2025/07/26 19:51:28 by kemontei           ###   ########.fr     */
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

void	clean_pokeframes(t_animated_sprite *pokemon, int frame)
{
	int	i;

	i = 0;
	if (!pokemon || !pokemon->frames)
		return ;
	while (i < frame)
		free (pokemon->frames[i++]);
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
	if (!img || !mlx)
		return ;
	if (player->Down0)
		mlx_destroy_image(mlx, player->Down0);
	if (player->Down1)
		mlx_destroy_image(mlx, player->Down1);
	if (player->Down2)
		mlx_destroy_image(mlx, player->Down2);
	if (player->Left0)
		mlx_destroy_image(mlx, player->Left0);
	if (player->Left1)
		mlx_destroy_image(mlx, player->Left1);
	if (player->Left2)
		mlx_destroy_image(mlx, player->Left2);
	if (player->Right0)
		mlx_destroy_image(mlx, player->Right0);
	if (player->Right1)
		mlx_destroy_image(mlx, player->Right1);
	if (player->Right2)
		mlx_destroy_image(mlx, player->Right2);
	if (player->Up0)
		mlx_destroy_image(mlx, player->Up0);
	if (player->Up1)
		mlx_destroy_image(mlx, player->Up1);
	if (player->Up2)
		mlx_destroy_image(mlx, player->Up2);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	clean_images(&game->img, game->mlx);
	clean_player(&game->player, game->mlx);
	if (game->collectables)
		free(game->collectables);
	if (game->map)
		clean_map(game->map);
	free(game);
}