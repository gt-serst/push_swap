#include "../includes/push_swap.h"

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
	
	while (*stack_a)
	{
		head = *stack_a;
		tail = ft_ndlast(*stack_a);
		printf("GET ELEM FROM TOP:\n");
		while (ft_get_chunk_from_top(stack_a, head) != 1)
			head = head->next;
		printf("Top elem in chunk 1:%d\n", head->data);
		printf("GET ELEM FROM BOTTOM:\n");
		while (ft_get_chunk_from_bottom(stack_a, tail) != 1)
			tail = tail->prev;
		printf("Bottom elem in chunk 1:%d\n", tail->data);
		ft_dispatch_chunk(stack_a, stack_b, head, tail);
	}
	printf("Stack A:");
	ft_print_list(*stack_a);
	printf("Stack B:");
	ft_print_list(*stack_b);
	return (stack_a);
}

t_data	**ft_sorting(t_data **stack_a, t_data **stack_b)
{
	if (ft_stack_size(stack_a) == 2)
		stack_a = ft_sort_2(stack_a);
	if (ft_stack_size(stack_a) == 3)
		stack_a = ft_sort_3(stack_a);
	if (ft_stack_size(stack_a) == 4 || ft_stack_size(stack_a) == 5)
		stack_a = ft_sort_5(stack_a, stack_b);
	if (ft_stack_size(stack_a) > 5)
		stack_a = ft_sort_100(stack_a, stack_b);
	return (stack_a);
}
