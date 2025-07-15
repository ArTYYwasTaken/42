/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/15 19:45:49 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/Libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define PX 128

typedef struct map
{
	char **grid;
	int height;
	int width;
	int player_x;
	int player_y;
	int col;
	int exit_x;
	int exit_y;
	
} t_map;

typedef struct image
{
	void **dialga;
	void **palkia;
	void **giratina;
	void *exit;
	void *floor;
	void *leftwall;
	void *rightwall;
	void *upperwall;
	void *lowerwall;
	void *upleftcorner;
	void *uprightcorner;
	void *outleftlwrcorner;
	void *outleftuprcorner;
	void *outrightlwrcorner;
	void *outrightuppercorner;
	
} t_image;

typedef struct game
{
	t_map *map;
	void *mlx;
	void *win;
	int exit;

} t_game;

t_map *gamestart(char *mapfile);
int map_fileformat(char *mapfile);
int map_getheight(char *mapfile);
t_map *map_gridfill(t_map *map, char *mapfile);
void clean_map(t_map *map);
void displaygrid(t_map *map);
int	map_validation(t_map *map);
int	mv_borders(t_map *map);
int mv_characters(t_map *map);
int	mv_player(t_map *map);
int	mv_exit(t_map *map);
int	mv_collectables(t_map *map);
int mv_path(t_map *map);
int mv_floodfill(t_map *map, int x, int y, int collectables);
int mv_width(t_map *map);

#endif