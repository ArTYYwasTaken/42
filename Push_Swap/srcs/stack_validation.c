/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:38:44 by marvin            #+#    #+#             */
/*   Updated: 2025/09/18 18:53:03 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	args_validation(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '\0')
			return (print_error(), false);
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (!ft_isdigit(args[i][j]))
			return (print_error(), false);
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (print_error(), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_num_dups(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (print_error(), false);
	temp = stack;
	while (stack)
	{
		temp = (stack)->next;
		while (temp)
		{
			if (temp->num == (stack)->num)
				return (print_error(), false);
			temp = temp->next;
		}
		stack = (stack)->next;
	}
	return (true);
}
