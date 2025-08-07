/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/07 17:27:16 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libs/Libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <time.h>

# define PX 128
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ENTER 36
# define ESC 53

typedef void* t_sprite;

typedef struct s_image
{
	t_sprite			exit;
	t_sprite			floor;
	t_sprite			W_wall;
	t_sprite			E_wall;
	t_sprite			N_wall;
	t_sprite			S_wall;
	t_sprite			NW_corner;
	t_sprite			NE_corner;
	t_sprite			bolder;
	t_sprite			dialga;
	t_sprite			player;
	
} t_image;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			col;
	int			exit_x;
	int			exit_y;
	int			moves;
	char		last_input;
	int			last_move;

} t_map;

typedef struct s_game
{
	t_image			img;
	t_map			*map;
	void			*mlx;
	void			*win;
	int				exit;

} t_game;

// gamestart.c
int			map_fileformat(char *mapfile);
int			map_getheight(char *mapfile);
void		displaygrid(t_map *map);
t_map		*map_gridfill(t_map *map, char *mapfile);
t_map		*gamestart(char *mapfile);

//	map_validation.c
int			mv_exit(t_map *map);
int			mv_player(t_map *map);
int			mv_characters(t_map *map);
int			mv_borders(t_map *map);
int			map_validation(t_map *map);

//	map_validation2.c
int			mv_collectables(t_map *map);
int			mv_floodfill(t_map *map, int x, int y, int collectables);
int			mv_path(t_map *map);

//	file_to_image.c
void		gamestart_map(t_game *game);

//	game_loop.c
t_sprite	wall_placement(t_image img,t_map *map, int y, int x);
void 		draw_sprite(t_game *game, t_sprite sprite, int y, int x);
void		draw_map_row(t_game *game, int y);
int 		draw_map(t_game *game);

//	key_inputs.c
void		check_col_exit(t_game *game, int y, int x);
void 		handle_enter(t_game *game, int y, int x);
int			key_inputs(int keycode, void *param);

//	movement.c
void    	move_up(t_game *game);
void    	move_down(t_game *game);
void    	move_left(t_game *game);
void    	move_right(t_game *game);

//	cleaning_functions.c
void		clean_map(t_map *map);
void		clean_images(t_game *game, void *mlx);
void		free_game(t_game *game);

//	display_messages.c
void		print_error(char *msg);
void		print_moves(t_game *game);

//	game_ending.c
void    	game_won(t_game *game);
void    	game_lost(t_game *game);

//	win-lose_messages.c
void		win_message(void);
void    	kakashi_thumbsup(void);
void		lose_message(void);
void    	rope(void);
void		rope2(void);

#endif