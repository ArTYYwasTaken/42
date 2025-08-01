/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-poke_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 01:12:42 by kemontei            #+#    #+#           */
/*   Updated: 2025/07/29 01:12:42 by kemontei           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_pokemon(t_collectable *collectables, int pokecount, t_image img)
{
	int	i;
	int	poke_type;
	int	frame_count;

	i = 0;
	while (i < pokecount)
	{
		poke_type = collectables[i].pokemon_type;
		frame_count = 1;
		if (poke_type == 0)
			frame_count = img.dialga.frame_count;
		else if (poke_type == 1)
			frame_count = img.palkia.frame_count;
		else if (poke_type == 2)
			frame_count = img.giratina.frame_count;
		collectables[i].frame = (collectables[i].frame + 1) % frame_count;
		i++;
	}
}

void	draw_map_row(t_game *game, t_collectable *col, int y)
{
	int			x;
	t_sprite	sprite;
	char		tile;

	x = 0;
	while (x < game->map->width)
	{
		tile = game->map->grid[y][x];
		if (tile == '1' || tile == '2' || tile == '3')
			sprite = wall_placement(game->img, game->map, x, y);
		else if (tile == 'P')
			sprite = game->player.Down0;
		else if (tile == 'E')
			sprite = game->img.exit;
		else if (tile == 'C')
			sprite = poke_tiles(game, col, x, y);
		else
			sprite = game->img.floor;
		draw_sprite(game, sprite, x, y);
		x++;
	}
}

void	draw_map(t_game *game, t_collectable *col)
{
	int y;

	y = 0;
	while (y < game->map->height)
	{
		draw_map_row(game, col, y, col_count);
		y++;
	}
}

int	game_loop(t_game *game)
{
	static int animation_timer = 0;
	
	animation_timer++;
	if (animation_timer >= 10)
	{
		animate_pokemon(game->collectables, game->map->col, game->img);
		animation_timer = 0;
	}
	draw_map(game, game->collectables);
	return (0);
}
