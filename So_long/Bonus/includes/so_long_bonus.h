/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/11 17:15:36 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libs/Libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <time.h>

# define PX 128
# define NUM_BOLDERS 2
# define NUM_POKE 3

typedef void* t_sprite;

typedef struct s_collectable
{
	int	x;
	int	y;
	int	pokemon_type;
	int	frame;

} t_collectable;

typedef struct animated_sprite
{
	t_sprite	*frames;
	int			frame_count;

} t_animated_sprite;

typedef struct s_player
{
	int			player_frame;
	int			player_frame_count;
	t_sprite	down0;
	t_sprite	down1;
	t_sprite	down2;
	t_sprite	up0;
	t_sprite	up1;
	t_sprite	up2;
	t_sprite	left0;
	t_sprite	left1;
	t_sprite	left2;
	t_sprite	right0;
	t_sprite	right1;
	t_sprite	right2;
	// int			x;
	// int			y;

} t_player;

typedef struct s_image
{
	t_animated_sprite	dialga;
	t_animated_sprite	palkia;
	t_animated_sprite	giratina;
	t_sprite			exit;
	t_sprite			floor;
	t_sprite			W_wall;
	t_sprite			E_wall;
	t_sprite			N_wall;
	t_sprite			S_wall;
	t_sprite			NW_corner;
	t_sprite			NE_corner;
	t_sprite			outSW_corner;
	t_sprite			outNW_corner;
	t_sprite			outSE_corner;
	t_sprite			outNE_corner;
	t_sprite			bolder_1;
	t_sprite			bolder_2;
	
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
	t_collectable	*collectables;
	t_player		player;
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
int			pokeframes(t_animated_sprite *pokemon, char *name, t_game *game);
void		gamestart_poke(t_image *image, t_game *game);
void		gamestart_player(t_player *player, t_game *game, int size);
void		gamestart_map(t_game *game);

//	randomization.c
void		poke_rand(t_collectable *col, int y, int x, int *i);
void		bolder_rand(t_map *map, int y, int x);
void		randomize_cell(t_map *map, t_collectable *col, int y, int x, int *i);
void		randomization(t_map *map, t_collectable *col, int *col_count);

//	game_loop.c
void		animate_pokemon(t_collectable *collectables, int pokecount, t_image *img);
void		draw_map_row(t_game *game, t_collectable *collectable, int y);
void 		draw_map(t_game *game, t_collectable *collectable);
int			game_loop(t_game *game);

//	draw_map_utils.c
t_sprite	wall_placement(t_image img,t_map *map, int y, int x);
void 		draw_sprite(t_game *game, t_sprite sprite, int y, int x);
int 		find_pokemon_index(t_game *game, int x, int y);
t_sprite	poke_tiles(t_game *game, t_collectable *collectable, int y, int x);

//	key_inputs.c
void		check_col_exit(t_game *game, int y, int x);
void 		handle_enter(t_game *game, int y, int x);
int			key_inputs(int keycode, void *param);

//	movement.c
void    	move_up(t_game *game);
void    	move_down(t_game *game);
void    	move_left(t_game *game);
void    	move_right(t_game *game);

//	movement_animation.c
void    	move_animation_up(t_game *game, int y, int x);
void    	move_animation_down(t_game *game, int y, int x);
void    	move_animation_left(t_game *game, int y, int x);
void    	move_animation_right(t_game *game, int y, int x);

// cleaning_free_game.c
int		free_game(t_game *game);

//	cleaning_functions.c
void		clean_map(t_map *map);
void		clean_pokeframes(t_animated_sprite *pokemon, int frame);
void		clean_images(t_image *img, void *mlx);
void		clean_player(t_player *player, void *mlx);
void		clean_player2(t_player *player, void *mlx);

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