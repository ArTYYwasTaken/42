/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/03 18:31:12 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/Libft/includes/libft.h"
# include <mlx.h>

typedef struct map_stuff
{
	char **grid;
	int height;
	int width;
	
} t_map;

typedef struct player_stuff
{
	char **player;
	int x;
	int y;
	
} t_player;

typedef struct game
{
	t_map *map;
	t_player *player;
	char *temp;
	int col;
	int exit;
	
} t_game;

int gamestart (t_game *game, char *mapfile);

#endif