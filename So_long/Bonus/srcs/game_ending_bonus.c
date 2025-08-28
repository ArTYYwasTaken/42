/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ending_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 05:44:00 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/28 17:31:09 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_won(t_game *game)
{
	win_message();
	kakashi_thumbsup();
	free_game(game);
}

void	game_lost(t_game *game)
{
	lose_message();
	rope();
	rope2();
	free_game(game);
}
