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

void	gamestart_map(t_game *game)
{
	int	size;

	size = PX;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/floor.xpm", &size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/exit.xpm", &size, &size);
	game->img.W_wall = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/Wwall.xpm", &size, &size);
	game->img.S_wall = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/Swall.xpm", &size, &size);
	game->img.E_wall = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/Ewall.xpm", &size, &size);
	game->img.N_wall = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/Nwall.xpm", &size, &size);
	game->img.NW_corner = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/NWwall.xpm", &size, &size);
	game->img.NE_corner = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/NEwall.xpm", &size, &size);
	game->img.bolder = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/WB/bolder1.xpm", &size, &size);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/Player/S0_Player.xpm", &size, &size);
	game->img.dialga = mlx_xpm_file_to_image(game->mlx,
			"../../sprites/Pokemons/dialga/dialga_0.xpm", &size, &size);
}
