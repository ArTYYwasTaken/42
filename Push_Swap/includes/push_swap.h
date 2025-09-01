/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:05:48 by kemontei          #+#    #+#             */
/*   Updated: 2025/09/01 16:31:05 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/includes/libft.h"
# include <stdbool.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				index;
	int				num;
	struct s_stack	*previous;
	struct s_stack	*next;

}	t_stack;

void	free_grid(char **grid);
void	print_error(char *msg);

#endif