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

int	ft_get_chunk_from_top(t_data **stack, t_data *head)
{
	int	pos;
	int	chunk;
	t_data	*temp;

	//printf("Elem:%d\n", head->data);
	pos = 0;
	temp = *stack;
	while (temp)
	{
		if (head->data >= temp->data)
			pos++;
		temp = temp->next;
	}
	//printf("Pos:%d\n", pos);
	chunk = (pos / 20) + 1;
	//printf("Chunk:%d\n", chunk);
	return (chunk);
}

int	ft_get_chunk_from_bottom(t_data **stack, t_data *tail)
{
	int	pos;
	int	chunk;
	t_data	*temp;

	//printf("Elem:%d\n", tail->data);
	pos = 0;
	temp = *stack;
	while (temp)
	{
		if (tail->data >= temp->data)
			pos++;
		temp = temp->next;
	}
	//printf("Pos:%d\n", pos);
	chunk = (pos / 20) + 1;
	//printf("Chunk:%d\n", chunk);
	return (chunk);
}

t_data	*ft_dispatch_chunk(t_data *hold_first, t_data *hold_second)
{
	if (hold_first->index <= 50 && hold_second->index > 50)
	{
		if (hold_first->index < (hold_second->index - 50))
			return (hold_first);
		else
			return (hold_second);
	}
	if (hold_first->index > 50 && hold_second->index > 50)
	{
		return (hold_second);
	}
	if (hold_first->index <= 50 && hold_second->index <= 50)
		return (hold_first);
	//random return if no matching conditions...
	return (hold_first);
}
