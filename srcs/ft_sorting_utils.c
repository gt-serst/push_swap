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
	while (head->next != NULL)
	{
		if (head->data == maxmin)
			break ;
		index++;
		head = head->next;
	}
	return (index);
}

int	ft_get_chunk(t_data *elem)
{
	int	chunk;

	//printf("Elem:%d\n", elem->data);
	//printf("Pos:%d\n", elem->index);
	if (elem->index % 20 == 0)
		chunk = (elem->index / 20);
	else
		chunk = ((elem->index) / 20) + 1;
	//printf("Chunk:%d\n", chunk);
	return (chunk);
}

/*
int	ft_get_chunk_from_bottom(t_data **stack, t_data *tail)
{
	int	pos;
	int	chunk;
	t_data	*temp;

	printf("Elem:%d\n", tail->data);
	pos = 0;
	temp = *stack;
	while (temp)
	{
		if (tail->data >= temp->data)
			pos++;
		temp = temp->next;
	}
	printf("Pos:%d\n", pos);
	chunk = (pos / 20) + 1;
	printf("Chunk:%d\n", chunk);
	return (chunk);
}
*/

void	ft_dispatch_chunk(t_data **stack_a, t_data **stack_b, t_data *head, t_data *tail)
{
	t_data	*hold_first;
	t_data	*hold_second;

	if (head->index <= 50 && tail->index > 50 && head->index < (tail->index - 50))
	{	
		hold_first = head;
		hold_second = tail;
	}
	else if (head->index <= 50 && tail->index <= 50)
	{
		hold_first = head;
		hold_second = tail;
	}
	else
	{
		hold_first = tail;
		hold_second = head;
	}
	ft_move_to_otherstack(stack_a, stack_b, hold_first);
	ft_move_to_otherstack(stack_a, stack_b, hold_second);
	//printf("STACK B:");
	//ft_print_list(*stack_b);
}

void	ft_move_to_otherstack(t_data **stack_a, t_data **stack_b, t_data *hold)
{
	t_data	*head;
	
	//printf("HELLO\n\n\n");
	//printf("hold:%d\n", hold->data);
	//ft_print_list(*stack_a);
	ft_swap_to_front(stack_a, hold);
	if (*stack_b == NULL)
	{
		pb(stack_a, stack_b);
		return ;
	}
	pb(stack_a, stack_b);
	head = *stack_b;
	while (head)
	{
		if (hold->data > head->data)
			return ;
		head = head->next;
	}
	rb(stack_b);
}
