/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-gamestart_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:06:45 by kemontei          #+#    #+#             */
/*   Updated: 2025/08/12 18:25:26 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	map_fileformat(char *mapfile)
{
	char	*pastdot;
	
	pastdot = ft_strrchr(mapfile, '.');
	if (!pastdot)
		return (0);
	if (ft_strncmp(pastdot, ".ber", 4))
		return (0);
	return (1);
}

static int	map_getheight(char *mapfile)
{
	int		fd;
	char	*line;
	int		count;
	
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (print_error("Invalid fd"), 0);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (close (fd), count);
}

static void	displaygrid(t_map *map)
{
	int	i;

	i = 0;
	while(map->grid[i])
	{
		ft_printf("%s\t%d\n", map->grid[i], ft_strlen(map->grid[i]));
		i++;	
	}
}

static t_map *map_gridfill(t_map *map, char *mapfile)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (print_error("Invalid fd"), NULL);
	map->grid[map->height] = NULL;
	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->grid[y++] = line;
	}
	map->width = ft_strlen(map->grid[0]);
	displaygrid(map);
	return (close (fd), map);
}

t_map *gamestart(char *mapfile)
{
	t_map	*map;
	
	map = malloc(sizeof(t_map));
	if (!map)
		return (print_error("Failed to allocate map"), free(map), NULL);
	if (!map_fileformat(mapfile))
		return (print_error("Invalid file format"), free(map), NULL);
	map->height = map_getheight(mapfile);
	if (map->height <= 2)
		return (print_error("Below map height required"), free(map), NULL);
	map->grid = malloc((map->height + 1) * sizeof(char *));
	if (!map->grid)
		return (print_error("Failed to allocate map grid"), free(map), NULL);
	map = map_gridfill(map, mapfile);
	if (!map->grid)
		return (print_error("Failed to load map"), clean_map(map), NULL);
	if (!map_validation(map))
		return (print_error("Failed map validation"), clean_map(map), NULL);
	return (map);
}
