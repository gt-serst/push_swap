#include "../includes/push_swap.h"

t_data	**ft_simple_swap_to_front(t_data **stack, int maxmin)
{
	if (ft_get_index(stack, maxmin) <= 3)
	{
		while (ft_get_index(stack, maxmin) != 0)
			ra(stack);
	}
	else
	{
		while (ft_get_index(stack, maxmin) != 0)
			rra(stack);
	}
	return (stack);
}

t_data	**ft_swap_to_front(t_data **stack, t_data *elem)
{
	if (elem->index <= 50)
	{
		while (elem->index != 0)
			ra(stack);
	}
	else
	{
		while (elem->index != 0)
			rra(stack);
	}
	return (stack);
}
