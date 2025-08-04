/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 05:26:01 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 05:26:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	clean_images(&game->img, game->mlx);
	clean_player(&game->player, game->mlx);
	clean_player2(&game->player, game->mlx);
	if (game->collectables)
		free(game->collectables);
	if (game->map)
		clean_map(game->map);
	free(game);
}
