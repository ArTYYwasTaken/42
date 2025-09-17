/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:25:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/09/17 18:33:14 by kemontei         ###   ########.fr       */
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
			return (print_error("Empty string caught in verification"), NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (print_error("Failed splitting"), free_grid(split), NULL);
		split_index = 0;
		while (split[split_index])
			grid[grid_index++] = ft_strdup(split[split_index++]);
		free_grid(split);
		i++;
	}
	grid[grid_index] = NULL;
	return (grid);
}

// void	print_nodes(t_stack	*stack_a)
// {
// 	ft_printf("\nStack A:\n");
// 	ft_printf("--//Number//--\t--//Index//--\n");
// 	while (stack_a)
// 	{
// 		ft_printf("%d\t\t%d\n", stack_a->num, stack_a->index);
// 		stack_a = stack_a->next;
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**grid;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (print_error("Invalid number of arguments"), 1);
	grid = grid_fill(argc, argv);
	if (!grid)
		return (print_error("Failed grid fill"), 1);
	fill_stack(&stack_a, grid);
	// print_nodes(stack_a);
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 5)
			small_sort(&stack_a, &stack_b, stack_size(stack_a));
		else
			radix_sort(&stack_a, &stack_b, stack_size(stack_a));
	}
	// print_nodes(stack_a);
	return (0);
}
