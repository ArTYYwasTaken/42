/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-so_long_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:53 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/25 17:04:34 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mlx_main(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (print_error("MLX initialization failed"), free_game(game));
	game->win = mlx_new_window(game->mlx, game->map->width * PX,
					game->map->height * PX, "PokeLong");
	if(!game->win)	
		return (print_error("Window creation failed"), free_game(game));
	gamestart_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_key_hook(game->win, key_inputs, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, finish_game, game);
	mlx_loop(game->mlx);
}

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
	game->collectables = malloc(sizeof(t_collectable) * game->map->col);
	if (!game->collectables)
		return (print_error("Collectable alloc failed"), free_game(game), 1);
	game->enemies = malloc(sizeof(t_enemy) * game->map->enemies);
	if (!game->enemies)
		return (print_error("Enemy alloc failed"), free_game(game), 1);
	randomization(game, game->map, &game->map->col, &game->map->enemies);
	mlx_main(game);
}
