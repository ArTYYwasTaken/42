/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:25:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/10/13 16:38:59 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**grid_fill(int argc, char **argv)
{
	char	**grid;
	char	**split;
	int		i;
	int		split_index;
	int		grid_index;

	grid = malloc (6700 * sizeof(char *));
	i = 1;
	grid_index = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (free_grid(split), NULL);
		split_index = 0;
		while (split[split_index])
			grid[grid_index++] = ft_strdup(split[split_index++]);
		free_grid(split);
		i++;
	}
	grid[grid_index] = NULL;
	return (grid);
}

void	print_nodes(t_stack *stack, const char *name)
{
	int count = 0;
	t_stack *tmp = stack;
	ft_printf("\nStack %s:\n", name ? name : "A");
	ft_printf("-----------------------------\n");
	ft_printf("|  Number  |  Index  |\n");
	ft_printf("-----------------------------\n");
	while (tmp)
	{
		ft_printf("| %d\t   |\t%d    |\n", tmp->num, tmp->index);
		tmp = tmp->next;
		count++;
	}
	ft_printf("-----------------------------\n");
	ft_printf("Total nodes: %d\n\n", count);
	if (count == 0)
		ft_printf("(Stack is empty)\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**grid;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (print_error(), 1);
	grid = grid_fill(argc, argv);
	if (!grid)
		return (print_error(), 1);
	fill_stack(&stack_a, grid);
	// print_nodes(stack_a, "A");
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 5)
			small_sort(&stack_a, &stack_b, stack_size(stack_a));
		else
			radix_sort(&stack_a, &stack_b, stack_size(stack_a));
	}
	// print_nodes(stack_a, "A");
	clean_push(&stack_a, &stack_b, grid);
	return (0);
}
