/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:25:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/09/15 15:35:46 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

char	**grid_fill(int argc, char **argv)
{
	char	**grid;
	char	**split;
	int		i;
	int		split_index;
	int		grid_index;
	
	grid = malloc (500 * sizeof(char *));
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

void	print_nodes(t_stack	*stack_a, t_stack *stack_b)
{
	ft_printf("--//Number//--\t--//Index//--\n");
	ft_printf("Stack A:\n");
	while (stack_a)
	{
		printf("%d\t%d\n", stack_a->num, stack_a->index);
		stack_a = stack_a->next;
	}
	ft_printf("Stack B:\n");
	while (stack_b)
	{
		printf("%d\t%d\n", stack_b->num, stack_b->index);
		stack_b = stack_b->next;
	}
}

int main(int argc, char **argv)
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
	print_nodes(stack_a, stack_b);
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 5)
			// small_sort(&stack_a, &stack_b, stack_size(stack_a));
			ft_printf("SMALL_SORT");
		else
			radix_sort(&stack_a, &stack_b, stack_size(stack_a));
	}
	return (0);	
}
