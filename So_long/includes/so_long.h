/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/07 18:34:13 by kemontei         ###   ########.fr       */
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
	int x;
	int y;
	
} t_player;

typedef struct game
{
	t_map *map;
	t_player *player;
	int col;
	int exit;
	
} t_game;

int gamestart (t_game *game, char *mapfile);
int map_fileformat(char *mapfile);
int map_getheight(t_game *game);
int map_gridfill(t_game *game);

#endif