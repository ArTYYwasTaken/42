/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:22:44 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/07 19:16:09 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_fileformat(char *mapfile)
{
	char	*pastdot;
	
	pastdot = ft_strrchr(mapfile, '.');
	if (!pastdot)
		return (0);
	if (ft_strncmp(pastdot, ".ber", 4))
		return (perror("Invalid file format\n"), 0);
	return (1);
}

int map_getheight(t_game *game)
{
	int		fd;
	char	*line;
	
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
		return (perror("Invalid fd"), 0);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (perror("Failed to allocate map"), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map->height++;
		free(line);
	}
	return (close (fd), 1);
}

void displaygrid(t_game *game)
{
	int i = 0;

	while(game->map->grid[i])
		ft_printf("%s\n", game->map->grid[i++]);
	i = 0;
	while(game->map->grid[i])
		ft_printf("\n%d", ft_strlen(game->map->grid[i++]));
}

int map_gridfill(t_game *game)
{
	int		fd;
	size_t	x;
	int	y;
	char	*line;

	game->map->grid = malloc((game->map->height + 1) * sizeof(char *));
	if (!game->map->grid)
		return (perror ("Failed to allocate map grid"), 0);
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
		return (perror ("Invalid fd"), 0);
	game->map->grid[game->map->height] = NULL;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		line = get_next_line(fd);
		if (!line)
			return (perror ("Failed to read line from file"), free(line), 0);
		game->map->grid[y] = malloc(gnl_strlen(line) + 1);
		if (!game->map->grid[y])
			return (perror ("Failed to allocate row"), 0);
		while (x < gnl_strlen(line))
		{
			game->map->grid[y][x] = line[x];
			x++;
		}
		game->map->grid[y][x] = '\0';
		free(line);
		y++;
	}
	displaygrid(game);
	return (close (fd), 1);
}
