#include "../includes/push_swap.h"

t_data	**ft_simple_swap_to_front(t_data **stack, t_data *elem)
{
	if (ft_get_spot(stack, elem) <= 3)
	{
		while (ft_get_spot(stack, elem) != 0)
			ra(stack);
	}
	else
	{
		while (ft_get_spot(stack, elem) != 0)
			rra(stack);
	}
	return (stack);
}

void	ft_swap_to_front(t_data **stack, t_data *elem)
{
	//printf("Hold chunk:%d\n", elem->data);
	//printf("Index hold chunk:%d\n", elem->index);
	//printf("Index fct:%d\n", ft_get_index(stack, elem->data));
	if (ft_get_spot(stack, elem) <= (ft_stack_size(stack) / 2))
	{
		while (ft_get_spot(stack, elem) != 0)
		{
			//printf("Index:%d\n", ft_get_index(stack, elem->data));
			ra(stack);
		}
	}
	else
	{
		while (ft_get_spot(stack, elem) != 0)
		{
			//printf("elem:%d\n", elem->data);
			//printf("ft_get_spot:%d\n", ft_get_spot(stack, elem));
			//ft_print_list(*stack);
			rra(stack);
		}
	}
}
