/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:50:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/18 20:07:57 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanframes(t_animated_sprite *pokemon, int frame)
{
	int	i;

	i = 0;
	while (i < frame)
		free (pokemon->frames[i++]);
	free(pokemon->frames);
	pokemon->frames = NULL;
}

int	pokeframes(t_animated_sprite *pokemon, char *name, t_game *game)
{
	int		i;
	int		size;
	char	filename[128];

	size = PX;
	i = 0;
	pokemon->frames = malloc(sizeof(t_sprite) * pokemon->frame_count);
	if (!pokemon->frames)
		return (perror("Failed to allocate poke frames"), 0);
	while (i < pokemon->frame_count)
	{
		sprintf(filename, "../sprites/Pokemons/%s/%s_%d.xpm", name, name, i);
		pokemon->frames[i] = mlx_xpm_file_to_image(game->mlx, filename,
				&size, &size);
		if (!pokemon->frames[i])
			return (cleanframes(pokemon, i), 0);
		i++;
	}
	return (1);
}

void	gamestart_poke(t_image *image, t_game *game)
{
	image->dialga.frame_count = 119;
	image->palkia.frame_count = 79;
	image->giratina.frame_count = 79;
	if (!pokeframes(&image->dialga, "dialga", game))
		perror("Failed to load Dialga frames\n");
	if (!pokeframes(&image->palkia, "palkia", game))
		perror("Failed to load Palkia frames\n");
	if (!pokeframes(&image->giratina, "giratina", game))
		perror("Failed to load Giratina frames\n");
}

void	gamestart_map(t_game *game)
{
	int	size;

	size = PX;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/floor.xpm", &size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/exit.xpm", &size, &size);
	game->img.W_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Ewall.xpm", &size, &size);
	game->img.S_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Swall.xpm", &size, &size);
	game->img.E_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Wwall.xpm", &size, &size);
	game->img.N_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Nwall.xpm", &size, &size);
	game->img.NW_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/NWwall.xpm", &size, &size);
	game->img.NE_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/NEwall.xpm", &size, &size);
	game->img.outNE_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerNEcorner.xpm", &size, &size);
	game->img.outNW_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerNWcorner.xpm", &size, &size);
	game->img.outSE_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerSEcorner.xpm", &size, &size);
	game->img.outSW_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerSWcorner.xpm", &size, &size);
	gamestart_poke(&game->img, game);
}
