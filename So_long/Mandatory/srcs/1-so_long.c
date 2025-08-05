/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:53 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/18 18:30:42 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (print_error("Invalid Number of Arguments"), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (print_error("Failed to allocate game"), 1);
	game->map = gamestart(argv[1]);
	if (!game->map)
		return (free_game(game), print_error("Failed to load map"), 1);
	game->collectables = malloc(sizeof(t_collectable) * game->map->col);
    if (!game->collectables)
        return (free_game(game), print_error("Collectable alloc failed"), 1);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game), print_error("MLX initialization failed"), 1);
	game->win = mlx_new_window(game->mlx, game->map->width * PX,
					game->map->height * PX, "PokeLong");
	if(!game->win)	
		return (free_game(game), print_error("Window creation failed"), 1);
	gamestart_map(game);
	mlx_loop_hook(game->mlx, draw_map, game);
	mlx_key_hook(game->mlx, key_inputs, game);
	mlx_loop(game->mlx);
}
