/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:06:45 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/03 18:46:20 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int gamestart(t_game *game, char *mapfile)
{
	char	*pastdot;
	char	*line;
	size_t	x;
	size_t	y;
	int		fd;
	
	pastdot = ft_strrchr(mapfile, '.');
	if (ft_strncmp(pastdot, ".ber", 4))
		return (perror("Invalid file format\n"), -1);
	fd = open("maps/map.ber", O_RDONLY);
	if (fd == -1)
		return (perror("Invalid fd"), -1);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (perror("Failed to allocate map"), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map->height++;
		ft_printf("%s", line);
	}
	ft_printf("\n%d\n", game->map->height);
	y = 0;
	game->map->grid = malloc((game->map->height + 1) * sizeof(char *));
	if (!game->map->grid)
		return (perror("Failed to allocate map grid"), -1);
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			line = get_next_line(fd);
			game->map->grid[y][x] = line[x];
			x++;
		}
		game->map->grid[y][x] = '\0';
		y++;
	}
	game->map->grid[y] = NULL;
}
