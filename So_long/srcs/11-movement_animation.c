/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10-movement_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 04:41:53 by kemontei            #+#    #+#           */
/*   Updated: 2025/07/30 04:41:53 by kemontei           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_animation_up(t_game *game, int y, int x)
{
    int frame;

	frame = game->map->last_move % 4;
	if (frame == 0)
		draw_sprite(game, game->player.up0, y, x);
	else if (frame == 1)
		draw_sprite(game, game->player.up1, y, x);
	else if (frame == 2)
		draw_sprite(game, game->player.up0, y, x);
	else if (frame == 3)
		draw_sprite(game, game->player.up2, y, x);
	game->map->last_move = (game->map->last_move + 1) % 4;
}

void    move_animation_down(t_game *game, int y, int x)
{
    int	frame;

	frame = game->map->last_move % 4;
	if (frame == 0)
		draw_sprite(game, game->player.down0, y, x);
	else if (frame == 1)
		draw_sprite(game, game->player.down1, y, x);
	else if (frame == 2)
		draw_sprite(game, game->player.down0, y, x);
	else if (frame == 3)
		draw_sprite(game, game->player.down2, y, x);
	game->map->last_move = (game->map->last_move + 1) % 4;
}

void    move_animation_left(t_game *game, int y, int x)
{
    int	frame;

	frame = game->map->last_move % 4;
	if (frame == 0)
		draw_sprite(game, game->player.left0, y, x);
	else if (frame == 1)
		draw_sprite(game, game->player.left1, y, x);
	else if (frame == 2)
		draw_sprite(game, game->player.left0, y, x);
	else if (frame == 3)
		draw_sprite(game, game->player.left2, y, x);
	game->map->last_move = (game->map->last_move + 1) % 4;
}

void    move_animation_right(t_game *game, int y, int x)
{
    int	frame;

	frame = game->map->last_move % 4;
	if (frame == 0)
		draw_sprite(game, game->player.right0, y, x);
	else if (frame == 1)
		draw_sprite(game, game->player.right1, y, x);
	else if (frame == 2)
		draw_sprite(game, game->player.right0, y, x);
	else if (frame == 3)
		draw_sprite(game, game->player.right2, y, x);
	game->map->last_move = (game->map->last_move + 1) % 4;
}
