#include "../includes/push_swap.h"

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

	max = ft_get_max(stack_a);
	min = ft_get_min(stack_a);
	stack_a = swap_to_front(stack_a, max);
	ft_print_list(*stack_a);
	pb(stack_a, stack_b);
	stack_a = swap_to_front(stack_a, min);
	pb(stack_a, stack_b);
	return (stack_a);
}
