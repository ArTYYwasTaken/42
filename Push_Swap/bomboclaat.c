static int	find_index_position(t_stack *stack, int target_index)
{
	int	pos;
	
	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	sort_three_optimal(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;
	
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

static void	push_back_optimized(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	target_index;
	int	b_size;
	int	pos;
	
	target_index = size - 1;
	while (*stack_b)
	{
		b_size = stack_size(*stack_b);
		if ((*stack_b)->index == target_index)
		{
			pa(stack_a, stack_b);
			target_index--;
		}
		else
		{
			pos = find_index_position(*stack_b, target_index);
			
			if (pos <= b_size / 2)
			{
				while ((*stack_b)->index != target_index)
					rb(stack_b);
			}
			else
			{
				while ((*stack_b)->index != target_index)
					rrb(stack_b);
			}
		}
	}
}

static void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;
	int	chunks;
	int	pushed;
	int	i;

	if (size <= 100)
		chunk_size = size / 5;
	else if (size <= 500)
		chunk_size = size / 11;
	else
		chunk_size = size / 20;
	
	chunks = (size + chunk_size - 1) / chunk_size;
	pushed = 0;
	i = 0;
	
	while (i < chunks && stack_size(*stack_a) > 3)
	{
		while (pushed < chunk_size * (i + 1) && stack_size(*stack_a) > 3)
		{
			if ((*stack_a)->index <= chunk_size * (i + 1) - 1)
			{
				pb(stack_b, stack_a);
				pushed++;
				if (*stack_b && (*stack_b)->next && (*stack_b)->index < chunk_size * i + chunk_size / 2)
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		i++;
	}
	
	if (stack_size(*stack_a) == 3)
		sort_three_optimal(stack_a);
	else if (stack_size(*stack_a) == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
	
	push_back_optimized(stack_a, stack_b, size);
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	optimized_radix_bit(t_stack **stack_a, t_stack **stack_b, int bit, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = (*stack_a)->index;
		if (((index >> bit) & 1) == 0)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_bits;
	int	bit;

	if (size <= 50)
	{
		max_bits = get_max_bits(size);
		bit = 0;
		while (bit < max_bits)
		{
			optimized_radix_bit(stack_a, stack_b, bit, stack_size(*stack_a));
			bit++;
		}
	}
	else
	{
		chunk_sort(stack_a, stack_b, size);
	}
}
