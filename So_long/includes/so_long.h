/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/18 19:39:50 by kemontei         ###   ########.fr       */
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

typedef void* t_sprite;

typedef struct animated_sprite
{
	t_sprite	*frames;
	int			frame_count;

} t_animated_sprite;

typedef struct player
{
	int			player_frame;
	int			player_frame_count;
	t_sprite	*player_sprites;
} t_player;

typedef struct image
{
	t_animated_sprite	dialga;
	t_animated_sprite	palkia;
	t_animated_sprite	giratina;
	t_sprite	exit;
	t_sprite	floor;
	t_sprite	W_wall;
	t_sprite	E_wall;
	t_sprite	N_wall;
	t_sprite	S_wall;
	t_sprite	NW_corner;
	t_sprite	NE_corner;
	t_sprite	outSW_corner;
	t_sprite	outNW_corner;
	t_sprite	outSE_corner;
	t_sprite	outNE_corner;
	
} t_image;

typedef struct game
{
	t_player player;
	t_image img;
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
void gamestart_map(t_game *game);
void gamestart_poke(t_image *image, t_game *game);
int pokeframes(t_animated_sprite *pokemon, char *name, t_game *game);
void cleanframes(t_animated_sprite *pokemon, int frame);

#endif