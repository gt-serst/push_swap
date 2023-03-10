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

int	ft_get_spot(t_data **stack, t_data *elem)
{
	int		spot;
	t_data	*head;

	spot = 0;
	head = *stack;
	while (head->next != NULL)
	{
		if (head->data == elem->data)
			break ;
		spot++;
		head = head->next;
	}
	return (spot);
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

int	ft_get_moves_to_top(int spot, int stack_size)
{
	int	moves_to_top;
	int	middle_spot;

	middle_spot = (stack_size / 2);
	if (spot <= middle_spot)
		moves_to_top = spot;
	else
		moves_to_top = (stack_size) - (spot);
	return (moves_to_top);
}

void	ft_dispatch_chunk(t_data **stack_a, t_data **stack_b, t_data *top, t_data *bottom)
{
	int		top_spot;
	int		bottom_spot;
	int		stack_size;

	//ft_print_list(*stack_a);	
	//printf("top:%d\n", top->data);
	top_spot = ft_get_spot(stack_a, top);
	//printf("top_spot:%d\n", top_spot);
	//printf("bottom:%d\n", bottom->data);
	bottom_spot = ft_get_spot(stack_a, bottom);
	//printf("bottom_spot:%d\n", bottom_spot);
	stack_size = ft_stack_size(stack_a);
	//printf("stack_size:%d\n", stack_size);
	if (ft_get_moves_to_top(top_spot, stack_size) <= ft_get_moves_to_top(bottom_spot, stack_size))
	{
		//printf("moves_from_top:%d\n", ft_get_moves_to_top(top_spot, stack_size));
		//printf("moves_from_bottom:%d\n", ft_get_moves_to_top(bottom_spot, stack_size));
		ft_move_to_otherstack(stack_a, stack_b, top);
		ft_move_to_otherstack(stack_a, stack_b, bottom);
	}
	else
	{
		ft_move_to_otherstack(stack_a, stack_b, bottom);
		ft_move_to_otherstack(stack_a, stack_b, top);
	}
	
	//printf("current stack size:%d\n", ft_stack_size(stack_a));
	//printf("head:%d\n", hold_first->data);
	//printf("head_spot:%d\n", head_spot);
	//printf("tail:%d\n", hold_second->data);
	//printf("tail_spot:%d\n", tail_spot);
/*
	if (head_spot <= middle_spot && tail_spot > middle_spot && head_spot < (middle_spot * 2) - tail_spot)
	{
		ft_move_to_otherstack(stack_a, stack_b, hold_first);
		ft_move_to_otherstack(stack_a, stack_b, hold_second);
	}
	else if (head_spot <= middle_spot && tail_spot <= middle_spot)
	{
		ft_move_to_otherstack(stack_a, stack_b, hold_first);
		ft_move_to_otherstack(stack_a, stack_b, hold_second);
	}
	else
	{
		ft_move_to_otherstack(stack_a, stack_b, hold_second);
		ft_move_to_otherstack(stack_a, stack_b, hold_first);
	}
*/
/*
	if (top_spot <= middle_spot && bottom_spot > middle_spot)
	{
		moves_from_top = top_spot;
		moves_from_bottom = (middle_spot * 2) - (bottom_spot + 1);
	}
	if (top_spot < middle_spot && tail_spot <= middle_spot)
	{
		moves_from_top = top_spot;
		moves_from_bottom = tail_spot;
	}
	if (top_spot >= middle_spot && tail_spot > middle_spot)
	{
		moves_from_top = (middle_spot * 2) - (top_spot + 1);
		moves_from_bottom = (middle_spot * 2) - (top_spot + 1);
	}
*/
	//printf("STACK B:");
	//ft_print_list(*stack_b);
}

void	ft_move_to_otherstack(t_data **stack_a, t_data **stack_b, t_data *hold)
{
	t_data	*head;
	
	//printf("Move to otherstack\n\n");
	//printf("hold:%d\n", hold->data);
	//ft_print_list(*stack_a);
	//printf("elem to swap:%d\n", hold->data);
	ft_swap_to_front(stack_a, hold);
	//printf("Correctly swap to front:%d\n", ft_get_spot(stack_a, hold));
	if (*stack_b == NULL)
	{
		pb(stack_a, stack_b);
		return ;
	}
	//printf("Stack A:");
	//ft_print_list(*stack_a);
	pb(stack_a, stack_b);
	//printf("New elem in stack B:\n\n");
	//ft_print_list(*stack_b);
	head = *stack_b;
	while (head)
	{
		if (hold->data > head->data)
			return ;
		head = head->next;
	}
	rb(stack_b);
}
