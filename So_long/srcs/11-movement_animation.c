/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10-movement_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 04:41:53 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 04:41:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_animation_up(t_game *game, int y, int x)
{
    game->map->last_move = 0;
    if (game->map->last_move == 0)
    {
        draw_sprite(game, game->player.Up0);
        game->map->last_move++;
    }
    if (game->map->last_move == 1)
    {
        draw_sprite(game, game->player.Up1);
        game->map->last_move++;
    }
    if (game->map->last_move == 2)
    {
        draw_sprite(game, game->player.Up0);
        game->map->last_move++;
    }
    if (game->map->last_move == 3)
    {
        draw_sprite(game, game->player.Up2);
        game->map->last_move++;
    }
}

void    move_animation_down(t_game *game, int y, int x)
{
    game->map->last_move = 0;
    if (game->map->last_move == 0)
    {
        draw_sprite(game, game->player.Down0);
        game->map->last_move++;
    }
    if (game->map->last_move == 1)
    {
        draw_sprite(game, game->player.Down1);
        game->map->last_move++;
    }
    if (game->map->last_move == 2)
    {
        draw_sprite(game, game->player.Down0);
        game->map->last_move++;
    }
    if (game->map->last_move == 3)
    {
        draw_sprite(game, game->player.Down2);
        game->map->last_move++;
    }
}

void    move_animation_left(t_game *game, int y, int x)
{
    game->map->last_move = 0;
    if (game->map->last_move == 0)
    {
        draw_sprite(game, game->player.Left0);
        game->map->last_move++;
    }
    if (game->map->last_move == 1)
    {
        draw_sprite(game, game->player.Left1);
        game->map->last_move++;
    }
    if (game->map->last_move == 2)
    {
        draw_sprite(game, game->player.Left0);
        game->map->last_move++;
    }
    if (game->map->last_move == 3)
    {
        draw_sprite(game, game->player.Left2);
        game->map->last_move++;
    }
}

void    move_animation_right(t_game *game, int y, int x)
{
    game->map->last_move = 0;
    if (game->map->last_move == 0)
    {
        draw_sprite(game, game->player.Right0);
        game->map->last_move++;
    }
    if (game->map->last_move == 1)
    {
        draw_sprite(game, game->player.Right1);
        game->map->last_move++;
    }
    if (game->map->last_move == 2)
    {
        draw_sprite(game, game->player.Right0);
        game->map->last_move++;
    }
    if (game->map->last_move == 3)
    {
        draw_sprite(game, game->player.Right2);
        game->map->last_move++;
    }
}
