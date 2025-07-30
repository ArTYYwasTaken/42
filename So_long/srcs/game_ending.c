/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ending.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 05:44:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 05:44:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    game_won(t_game *game)
{
    free_game(game);
    win_message();
    kakashi_thumbsup();
}

void    game_lost(t_game *game)
{
    free_game(game);
    lose_message();
    rope();
    rope2();
}