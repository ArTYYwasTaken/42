/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:57 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/14 21:37:50 by kemontei         ###   ########.fr       */
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
# define NUM_ENEMY 6

typedef void*	t_sprite;

typedef struct s_collectable
{
	int	x;
	int	y;
	int	pokemon_type;
	int	frame;

}	t_collectable;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	enemy_type;
	int	frame;

}	t_enemy;

typedef struct animated_sprite
{
	t_sprite	*frames;
	int			frame_count;

}	t_animated_sprite;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,

}	t_direction;

typedef struct s_player
{
	int			player_frame;
	int			player_frame_count;
	t_sprite	sprites[4][4];
	t_direction	direction;

}	t_player;

typedef struct s_image
{
	t_animated_sprite	dialga;
	t_animated_sprite	palkia;
	t_animated_sprite	giratina;
	t_animated_sprite	colress;
	t_animated_sprite	ghetsis;
	t_animated_sprite	n;
	t_animated_sprite	plasmaF;
	t_animated_sprite	plasmaM;
	t_animated_sprite	scientist;
	t_sprite			exit;
	t_sprite			floor;
	t_sprite			w_wall;
	t_sprite			e_wall;
	t_sprite			n_wall;
	t_sprite			s_wall;
	t_sprite			nw_corner;
	t_sprite			ne_corner;
	t_sprite			bolder_1;
	t_sprite			bolder_2;
	t_sprite			gameboy;

}	t_image;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			col;
	int			enemies;
	int			exit_x;
	int			exit_y;
	int			moves;
	char		last_input;
	int			last_move;

}	t_map;

typedef struct s_game
{
	t_collectable	*collectables;
	t_enemy			*enemies;
	t_player		player;
	t_image			img;
	t_map			*map;
	void			*mlx;
	void			*win;
	int				exit;

}	t_game;

/*					gamestart.c 											*/
/* static int	map_fileformat(char *mapfile);								*/
/* static int	map_getheight(char *mapfile);								*/
/* static void	displaygrid(t_map *map);									*/
/* static t_map	*map_gridfill(t_map *map, char *mapfile);					*/
t_map		*gamestart(char *mapfile);

/*					map_validation.c										*/
/* static int	mv_exit(t_map *map);										*/
/* static int	mv_player(t_map *map);										*/
/* static int	mv_characters(t_map *map);									*/
/* static int	mv_borders(t_map *map);										*/
int			map_validation(t_map *map);

/* 							map_validation2.c 								*/
/* int	mv_floodfill(t_map *map, int x, int y, int collectables);			*/
int			mv_collectables(t_map *map);
int			mv_path(t_map *map);

/*								file_to_image.c								*/
/*	static void	gamestart_wb(t_image *image, t_game *game, int size);		*/
void		gamestart_player(t_player *player, t_game *game, int size);
void		gamestart_player2(t_player *player, t_game *game, int size);
void		gamestart_map(t_game *game);

/*								FTI-poke-enemy.c							*/
int			pokeframes(t_animated_sprite *pokemon, char *name, t_game *game);
void		gamestart_poke(t_image *image, t_game *game);
int			enemyframes(t_animated_sprite *enemy, char *name, t_game *game);
void		gamestart_enemies(t_image *image, t_game *game);

/*								randomization.c								 */
/* void	poke_rand(t_collectable *col, int y, int x, int *i);				 */
/* void	bolder_rand(t_map *map, int y, int x);								 */
/* void	randomize_cell(t_map *map, t_collectable *col, int y, int x, int *i);*/
/* void	enemy_rand(t_enemy *enemy, int y, int x, int *i);					 */
void		randomization(t_game *game, t_map *map, int *col_count, int *enemy_count);

/*								game_loop.c									*/
/* void	animate_pokemon(t_collectable *collectables,						*/
/*						int pokecount, t_image *img);						*/
/* void	animate_enemy(t_enemy *enemy, int enemycount, t_image *img);		*/
/* void	draw_map_row(t_game *game, t_collectable *collectable,				*/
/*					 t_enemy *enemy, int y)									*/
/* void	draw_map(t_game *game, t_map *map)									*/
int			game_loop(t_game *game);

/*								draw_map_utils.c							*/
t_sprite	wall_placement(t_image img, t_map *map, int y, int x);
void		draw_sprite(t_game *game, t_sprite sprite, int y, int x);
int			find_pokemon_index(t_game *game, int x, int y);
t_sprite	poke_tiles(t_game *game, t_collectable *collectable, int y, int x);

/*								draw_map_utils2.c							*/
int			find_enemy_index(t_game *game, int x, int y);
t_sprite	enemy_tiles(t_game *game, t_enemy *enemy, int y, int x);

/*						key_inputs.c							*/
/* static void	remove_collectable(t_game *game, int x, int y);	*/
/* static void	check_col_exit(t_game *game, int y, int x);		*/
/* static void 	handle_enter(t_game *game, int y, int x);		*/
/* static void	remove_enemy(t_game *game, int x, int y);		*/
int			key_inputs(int keycode, t_game *game);

/*								movement.c									*/
void		move_animation(t_game *game, t_direction direction, int y, int x);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

/*					cleaning_free_game.c						*/
void		clean_map(t_map *map);
void		free_game(t_game *game);
int			finish_game(t_game *game);

/*					cleaning_functions.c							*/
void		clean_pokeframes(t_animated_sprite *pokemon, int frame);
void		clean_enemyframes(t_animated_sprite *enemy, int frame);
void		clean_images(t_image *img, void *mlx);
void		clean_worldbuilding(t_image *img, void *mlx);
void		clean_player(t_player *player, void *mlx);

/*					display_messages.c							*/
void		print_error(char *msg);
void		print_moves(t_game *game);

/*					game_ending.c								*/
void		game_won(t_game *game);
void		game_lost(t_game *game);

/*					win-lose_messages.c							*/
void		win_message(void);
void		kakashi_thumbsup(void);
void		lose_message(void);
void		rope(void);
void		rope2(void);

#endif