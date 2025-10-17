/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:05:48 by kemontei          #+#    #+#             */
/*   Updated: 2025/10/17 17:54:42 by kemontei         ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;

}	t_stack;

void	print_error();
long	ft_atol(const char *str);
int		num_len(long num);
void	free_grid(char **grid);
void	clear_stack(t_stack **stack_a);
void	clean_push(t_stack **stack_a, t_stack **stack_b, char **args);
bool	fill_stack(t_stack **stack_a, char **args);
void	stack_new(t_stack **stack, int num);
t_stack	*stack_last(t_stack *stack);
size_t	stack_size(t_stack *stack);
bool	check_num_dups(t_stack *stack);
bool	args_validation(char **args);
void	indexing(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
bool	stack_sorted(t_stack *stack_a);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	small_sort(t_stack **stack_a, t_stack **stack_b, int size);
#endif