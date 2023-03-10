#include "../includes/push_swap.h"

void	ft_put_index(t_data **stack)
{
	int	pos;
	t_data	*head;
	t_data	*temp;

	head = *stack;
	while (head)
	{
		pos = 0;
		temp = *stack;
		while (temp)
		{
			if (head->data >= temp->data)
				pos++;
			temp = temp->next;
		}
		head->index = pos;
		head = head->next;
	}
}

int	ft_stack_size(t_data **stack)
{
	int	stack_size;
	t_data	*head;

	stack_size = 0;
	head = *stack;
	while ((*stack))
	{
		*stack = (*stack)->next;
		stack_size++;
	}
	*stack = head;
	return (stack_size);
}

t_data	**ft_sort_100(t_data **stack_a, t_data **stack_b)
{
	t_data	*head;
	t_data	*tail;
	int	count;
	int	chunk;
	int	chunk_max;

	count = 0;
	chunk = 1;
	chunk_max = (ft_stack_size(stack_a) / 20) + 1;
	//ft_print_list(*stack_a);
	while (*stack_a && chunk <= chunk_max)
	{
		//printf("STACK A\n");
		//ft_print_list(*stack_a);
		//printf("STACK B\n");
		//ft_print_list(*stack_b);
		//printf("CHUNK \n %d\n", chunk);
		head = *stack_a;
		tail = ft_ndlast(*stack_a);
		if (head != tail)
		{
			//printf("GET ELEM FROM TOP:\n");
			while (head && ft_get_chunk(head) != chunk)
				head = head->next;
			//printf("Top elem in chunk %d:%d\n", chunk, head->data);
			//printf("GET ELEM FROM BOTTOM:\n");
			while (tail && ft_get_chunk(tail) != chunk)
			{
				tail = tail->prev;
				//printf("TAIL DATA: %d\n", tail->data);
			}
			//printf("tail->data: %d\n", tail->data);
			//printf("Index tail->data: %d\n", ft_get_index(stack_a, tail->data));
			//printf("Bottom elem in chunk %d:%d\n", chunk, tail->data);
			if (!tail || ft_get_chunk(tail) != chunk)
			{
				ft_move_to_otherstack(stack_a, stack_b, head);
				count++;
				//printf("count :%d\n", count);
			}
			else
			{
				//printf("head:%d\n", head->data);
				//printf("head->next:%d\n", head->next->data);
				//printf("tail:%d\n", tail->data);
				//printf("tail->prev:%d\n", tail->prev->data);
				ft_dispatch_chunk(stack_a, stack_b, head, tail);
				count += 2;
			}
		}
		else
		{
			ft_move_to_otherstack(stack_a, stack_b, head);
			count++;
		}
		if (count == 20)
		{
			chunk++;
			count = 0;
		}
	}
	//printf("Stack A:");
	//ft_print_list(*stack_a);
	//printf("Stack B:");
	//ft_print_list(*stack_b);
	ft_get_final_stack(stack_a, stack_b);
	return (stack_a);
}

t_data	**ft_sorting(t_data **stack_a, t_data **stack_b)
{
	ft_put_index(stack_a);
	if (ft_stack_size(stack_a) == 2)
		stack_a = ft_sort_2(stack_a);
	if (ft_stack_size(stack_a) == 3)
		stack_a = ft_sort_3(stack_a);
	if (ft_stack_size(stack_a) == 4)
		stack_a = ft_sort_4(stack_a, stack_b);
	if (ft_stack_size(stack_a) == 5)
		stack_a = ft_sort_5(stack_a, stack_b);
	if (ft_stack_size(stack_a) > 5)
		stack_a = ft_sort_100(stack_a, stack_b);
	return (stack_a);
}
