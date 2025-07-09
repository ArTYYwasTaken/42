/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:15:53 by kemontei          #+#    #+#             */
/*   Updated: 2025/07/09 16:31:44 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Invalid Number of Arguments"));
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->map = gamestart(argv[1]);
	if (!game->map)
		return (ft_printf("Merda\n"));
	free(game->map);
	free (game);
	return (ft_printf("Trnql\n"));
}
