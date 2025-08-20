/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-FTI-poke-enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 02:29:22 by marvin            #+#    #+#             */
/*   Updated: 2025/08/20 02:29:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	pokeframes(t_animated_sprite *pokemon, char *name, t_game *game)
{
	int		i;
	int		size;
	char	filename[128];

	size = PX;
	i = 0;
	pokemon->frames = malloc(sizeof(t_sprite) * pokemon->frame_count);
	if (!pokemon->frames)
		return (print_error("Failed to allocate poke frames"), 0);
	while (i < pokemon->frame_count)
	{
		sprintf(filename, "./sprites/Pokemons/%s/%s_%d.xpm", name, name, i);
		pokemon->frames[i] = mlx_xpm_file_to_image(game->mlx, filename,
				&size, &size);
		if (!pokemon->frames[i])
			return (clean_pokeframes(pokemon, i), 0);
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
		print_error("Failed to load Dialga frames");
	if (!pokeframes(&image->palkia, "palkia", game))
		print_error("Failed to load Palkia frames");
	if (!pokeframes(&image->giratina, "giratina", game))
		print_error("Failed to load Giratina frames");
}

int	enemyframes(t_animated_sprite *enemy, char *name, t_game *game)
{
	int		i;
	int		size;
	char	filename[128];

	size = PX;
	i = 0;
	enemy->frames = malloc(sizeof(t_sprite) * enemy->frame_count);
	if (!enemy->frames)
		return (print_error("Failed to allocate enemy frames"), 0);
	while (i < enemy->frame_count)
	{
		sprintf(filename, "./sprites/Enemies/%s/%s_%d.xpm", name, name, i);
		enemy->frames[i] = mlx_xpm_file_to_image(game->mlx, filename,
				&size, &size);
		if (!enemy->frames[i])
			return (clean_enemyframes(enemy, i), 0);
		i++;
	}
	return (1);
}

void	gamestart_enemies(t_image *image, t_game *game)
{
	image->colress.frame_count = 36;
	image->ghetsis.frame_count = 56;
	image->n.frame_count = 11;
	image->plasmaF.frame_count = 12;
	image->plasmaM.frame_count = 18;
	image->scientist.frame_count = 23;
	if (!pokeframes(&image->colress, "colress", game))
		print_error("Failed to load Colress frames");
	if (!pokeframes(&image->ghetsis, "ghetsis", game))
		print_error("Failed to load Ghetsis frames");
	if (!pokeframes(&image->n, "n", game))
		print_error("Failed to load N frames");
	if (!pokeframes(&image->plasmaF, "plasmaF", game))
		print_error("Failed to load Plasma Female frames");
	if (!pokeframes(&image->plasmaM, "plasmaM", game))
		print_error("Failed to load Plasma male frames");
	if (!pokeframes(&image->scientist, "scientist", game))
		print_error("Failed to load Scientist frames");
}
