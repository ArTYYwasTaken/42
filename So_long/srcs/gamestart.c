/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:06:45 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/07 19:09:21 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int gamestart(t_game *game, char *mapfile)
{
	size_t	i;

	i = 0;
	if (!map_fileformat(mapfile))
		return (0);
	else if (!map_getheight(game))
		return (0);
	else if (!map_gridfill(game))
		return (0);
    free(game->map->grid);
	return (1);
}
