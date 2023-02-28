#include "../includes/push_swap.h"

t_data	**swap_to_front(t_data **stack, int maxmin)
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
