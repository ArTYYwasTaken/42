/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-file_to_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:50:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/25 14:46:44 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	gamestart_player(t_player *player, t_game *game, int size)
{
	player->sprites[DOWN][0] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S0_Player.xpm", &size, &size);
	player->sprites[DOWN][1] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S1_Player.xpm", &size, &size);
	player->sprites[DOWN][2] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S0_Player.xpm", &size, &size);
	player->sprites[DOWN][3] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/S3_Player.xpm", &size, &size);
	player->sprites[LEFT][0] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W0_Player.xpm", &size, &size);
	player->sprites[LEFT][1] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W1_Player.xpm", &size, &size);
	player->sprites[LEFT][2] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W0_Player.xpm", &size, &size);
	player->sprites[LEFT][3] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/W3_Player.xpm", &size, &size);
	gamestart_player2(player, game, size);
}

void	gamestart_player2(t_player *player, t_game *game, int size)
{
	player->sprites[RIGHT][0] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E0_Player.xpm", &size, &size);
	player->sprites[RIGHT][1] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E1_Player.xpm", &size, &size);
	player->sprites[RIGHT][2] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E0_Player.xpm", &size, &size);
	player->sprites[RIGHT][3] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/E3_Player.xpm", &size, &size);
	player->sprites[UP][0] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N0_Player.xpm", &size, &size);
	player->sprites[UP][1] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N1_Player.xpm", &size, &size);
	player->sprites[UP][2] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N0_Player.xpm", &size, &size);
	player->sprites[UP][3] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/Player/N3_Player.xpm", &size, &size);
	game->player.direction = DOWN;
}

static void	gamestart_wb(t_image *image, t_game *game, int size)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/floor.xpm", &size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/exit.xpm", &size, &size);
	game->img.w_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Wwall.xpm", &size, &size);
	game->img.s_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Swall.xpm", &size, &size);
	game->img.e_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Ewall.xpm", &size, &size);
	game->img.n_wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/Nwall.xpm", &size, &size);
	game->img.nw_corner = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/NWcorner.xpm", &size, &size);
	game->img.ne_corner = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/NEcorner.xpm", &size, &size);
	game->img.bolder_1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/bolder1.xpm", &size, &size);
	game->img.bolder_2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/bolder2.xpm", &size, &size);
	game->img.gameboy = mlx_xpm_file_to_image(game->mlx,
			"./sprites/WB/gameboy.xpm", &size, &size);
}

void	gamestart_map(t_game *game)
{
	int	size;

	size = PX;
	gamestart_poke(&game->img, game);
	gamestart_enemies(&game->img, game);
	gamestart_player(&game->player, game, size);
	gamestart_wb(&game->img, game, size);
}
