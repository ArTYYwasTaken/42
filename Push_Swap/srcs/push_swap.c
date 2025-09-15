/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:25:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/09/01 16:55:19 by kemontei         ###   ########.fr       */
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
			return (perror("Empty string caught in verification"), NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (free_grid(split), perror("Failed splitting"), NULL);
		split_index = 0;
		while (split[split_index])
			grid[grid_index++] = ft_strdup(split[split_index++]);
		free_grid(split);
		i++;
	}
	grid[grid_index] = NULL;
	return (grid);
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
		return (perror("Failed grid fill"), 1);
	fill_stack(&stack_a, grid);
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 5)
			small_sort();
		else
			radix_sort();
	}
	// int i = 0;
	// while(grid[i])
	// {
	// 	ft_printf("%s\n", grid[i++]);
	// }
	// free_grid(grid);
	return (0);	
}
