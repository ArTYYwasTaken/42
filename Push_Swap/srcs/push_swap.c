/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:25:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/10/17 19:34:28 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*					Script						*/
/* maior=0										*/
/* for i in $(seq 1 10); do						*/
/*     a=$(shuf -e $(seq 1 100) | tr '\n' ' ')	*/
/*     linhas=$(./push_swap $a | wc -l)			*/
/*     echo "$linhas"							*/
/*     if [ "$linhas" -gt "$maior" ]; then		*/
/*         maior=$linhas						*/
/*     fi										*/
/* done											*/
/* echo "Maior: $maior"							*/

#include "push_swap.h"

static bool	initial_validation(char *arg)
{
	size_t	i;
	size_t	space_count;

	i = 0;
	space_count = 0;
	if (!arg[0])
		return (false);
	while (arg[i])
	{
		if (arg[i] == ' ')
			space_count++;
		i++;
	}
	if (space_count == ft_strlen(arg))
		return (false);
	return (true);
}

char	**grid_fill(int argc, char **argv)
{
	char	**grid;
	char	**split;
	int		i;
	int		split_index;
	int		grid_index;

	grid = ft_calloc(1, 6700 * sizeof(char *));
	if (!grid)
		return (NULL);
	i = 0;
	grid_index = 0;
	while (++i < argc)
	{
		if (!initial_validation(argv[i]))
			return (free_grid(grid), NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (free_grid(split), NULL);
		split_index = 0;
		while (split[split_index])
			grid[grid_index++] = ft_strdup(split[split_index++]);
		free_grid(split);
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
		return (1);
	grid = grid_fill(argc, argv);
	if (!grid)
		return (print_error(), 1);
	if (!fill_stack(&stack_a, grid))
		return (clean_push(&stack_a, &stack_b, grid), -1);
	print_nodes(stack_a, "A");
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 5)
			small_sort(&stack_a, &stack_b, stack_size(stack_a));
		else
			radix_sort(&stack_a, &stack_b, stack_size(stack_a));
	}
	print_nodes(stack_a, "A");
	clean_push(&stack_a, &stack_b, grid);
	return (0);
}
