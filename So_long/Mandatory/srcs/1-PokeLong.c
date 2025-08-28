/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:53 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/25 20:14:12 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (print_error("Invalid Number of Arguments"), 1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_error("Failed to allocate game"), 1);
	game->map = gamestart(argv[1]);
	if (!game->map)
		return (print_error("Failed to load map"), free_game(game), 1);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (print_error("MLX initialization failed"), free_game(game), 1);
	game->win = mlx_new_window(game->mlx, game->map->width * PX,
					game->map->height * PX, "PokeLong");
	if(!game->win)	
		return (print_error("Window creation failed"), free_game(game), 1);
	gamestart_map(game);
	mlx_loop_hook(game->mlx, draw_map, game);
	mlx_key_hook(game->win, key_inputs, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, finish_game, game);
	mlx_loop(game->mlx);
}
