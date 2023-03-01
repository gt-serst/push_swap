#include "../includes/push_swap.h"

t_data	**ft_sort_2(t_data **stack_a)
{
	int top;
	int bottom;

	top = (*stack_a)->data;
	bottom = (*stack_a)->next->data;
	if (top > bottom)
		sa(stack_a);
	return (stack_a);
}

t_data	**ft_sort_3(t_data **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->data;
	middle = (*stack_a)->next->data;
	bottom = (*stack_a)->next->next->data;
	if (top > middle && middle < bottom && bottom > top)
		sa(stack_a);
	if (top < middle && middle > bottom && bottom < top)
		rra(stack_a);
	if (top > middle && middle > bottom && bottom < top)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (top > middle && middle < bottom && bottom < top)
		ra(stack_a);
	if (top < middle && middle > bottom && bottom > top)
	{
		sa(stack_a);
		ra(stack_a);
	}
	return (stack_a);
}

t_data	**ft_sort_5(t_data **stack_a, t_data **stack_b)
{
	int	max;
	int	min;

	min = ft_get_min(stack_a);
	if (ft_stack_size(stack_a) == 4)
	{
		stack_a = ft_simple_swap_to_front(stack_a, min);
		pb(stack_a, stack_b);
		ft_sort_3(stack_a);
		pa(stack_b, stack_a);
	}
	else
	{
		max = ft_get_max(stack_a);
		stack_a = ft_simple_swap_to_front(stack_a, max);
		pb(stack_a, stack_b);
		stack_a = ft_simple_swap_to_front(stack_a, min);
		pb(stack_a, stack_b);
		ft_sort_3(stack_a);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
		ra(stack_a);
	}
	return (stack_a);
}
