/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-file_to_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:50:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/07 17:12:54 by kemontei         ###   ########.fr       */
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

void	gamestart_player(t_player player, t_game *game, int size)
{
	player.down0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S0_Player.xpm", &size, &size);
	player.down1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S1_Player.xpm", &size, &size);
	player.down2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S3_Player.xpm", &size, &size);
	player.left0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W0_Player.xpm", &size, &size);
	player.left1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W1_Player.xpm", &size, &size);
	player.left2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W3_Player.xpm", &size, &size);
	player.right0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E0_Player.xpm", &size, &size);
	player.right1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E1_Player.xpm", &size, &size);
	player.right2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E3_Player.xpm", &size, &size);
	player.up0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N0_Player.xpm", &size, &size);
	player.up1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N1_Player.xpm", &size, &size);
	player.up2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N3_Player.xpm", &size, &size);
}

void	gamestart_map(t_game *game)
{
	int	size;

	size = PX;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/floor.xpm", &size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/exit.xpm", &size, &size);
	game->img.W_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Wwall.xpm", &size, &size);
	game->img.S_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Swall.xpm", &size, &size);
	game->img.E_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Ewall.xpm", &size, &size);
	game->img.N_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Nwall.xpm", &size, &size);
	game->img.NW_corner = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/NWwall.xpm", &size, &size);
	game->img.NE_corner = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/NEwall.xpm", &size, &size);
	game->img.bolder_1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/bolder1.xpm", &size, &size);
	game->img.bolder_2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/bolder2.xpm", &size, &size);
	gamestart_poke(&game->img, game);
	gamestart_player(game->player, game, size);
}
