#include "../includes/push_swap.h"

int	ft_get_max(t_data **stack)
{
	int	max;
	t_data	*head;
	t_data	*next;
	
	head = *stack;
	max = (*stack)->data;
	while ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		if (max < next->data)
			max = next->data;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (max);
}

int	ft_get_min(t_data **stack)
{
	int	min;
	t_data	*head;
	t_data	*next;

	head = *stack;
	min = (*stack)->data;
	while ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		if (min > next->data)
			min = next->data;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (min);
}

int	ft_get_index(t_data **stack, int maxmin)
{
	int	index;
	t_data	*head;

	index = 0;
	head = *stack;
	while ((*stack)->next != NULL)
	{
		if ((*stack)->data == maxmin)
			break ;
		index++;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (index);
}
