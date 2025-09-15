/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:08:21 by marvin            #+#    #+#             */
/*   Updated: 2025/09/15 15:29:04 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	stack_new(t_stack **stack, int num)
{
	t_stack *new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->index = 0;
	new_node->next = NULL;
	if (!(*stack))
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		(stack_last(*stack)->next) = new_node;
		new_node->prev = stack_last(*stack);
	}
}

void	indexing(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = (*stack);
	while (current)
	{
		next = (*stack);
		while (next)
		{
			if (current->num > next->num)
				current->index++;
			next = next->next;
		}
		current = current->next;
	}
}

void	fill_stack(t_stack **stack_a, char **args)
{
	long	num;
	size_t	i;

	if (!args_validation(args))
		return (print_error("Failed args validation"));
	i = 0;
	while(args[i])
	{
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX || num_len(num) > 10)
			clear_stack_args(stack_a, args);
		stack_new(stack_a, (int)num);
		if (!check_num_dups(stack_a))
			return (print_error("Failed dup validation"));
	}
	indexing(stack_a);
}
