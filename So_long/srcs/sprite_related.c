/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:50:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/18 19:00:18 by kemontei         ###   ########.fr       */
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

void	pokeframes(t_animated_sprite *pokemon, char *name, t_game *game)
{
	int		i;
	int		size;
	char	filename[75];

	size = PX;
	i = 0;
	pokemon->frames = malloc(sizeof(t_sprite) * pokemon->frame_count);
	if (!pokemon->frames)
		return (perror("Failed to allocate poke frames"));
	while (i < pokemon->frame_count)
	{
		sprintf(filename, "../sprites/Pokemons/%s/%s_%d.png", name, name, i);
		pokemon->frames[i] = mlx_xpm_file_to_image(game->mlx, filename,
				&size, &size);
		if (!pokemon->frames[i])
			return (cleanframes(pokemon, i));
		i++;
	}
}

void	gamestart_poke(t_image *image, t_game *game)
{
	image->dialga.frame_count = 118;
	image->palkia.frame_count = 78;
	image->giratina.frame_count = 78;
	pokeframes(&image->dialga, "dialga", game);
	pokeframes(&image->palkia, "palkia", game);
	pokeframes(&image->giratina, "giratina", game);
}

void	gamestart_map(t_game *game)
{
	int	size;

	size = PX;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/floor.png", &size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/exit.png", &size, &size);
	game->img.W_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Ewall.png", &size, &size);
	game->img.S_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Swall.png", &size, &size);
	game->img.E_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Wwall.png", &size, &size);
	game->img.N_wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/Nwall.png", &size, &size);
	game->img.NW_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/NWwall.png", &size, &size);
	game->img.NE_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/NEwall.png", &size, &size);
	game->img.outNE_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerNEcorner.png", &size, &size);
	game->img.outNW_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerNWcorner.png", &size, &size);
	game->img.outSE_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerSEcorner.png", &size, &size);
	game->img.outSW_corner = mlx_xpm_file_to_image(game->mlx,
			"../sprites/WB/outerSWcorner.png", &size, &size);
	gamestart_poke(&game->img, game);
}
