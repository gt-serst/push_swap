/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:42 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/20 19:24:44 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_data	**ft_sort_100(t_data **stack_a, t_data **stack_b, int right_chunk)
{
	t_data	*head;
	t_data	*tail;
	int	chunk;
	int	chunk_max;

	chunk = 1;
	chunk_max = (ft_stack_size(stack_a) / right_chunk) + 1;
	while (*stack_a && chunk <= chunk_max)
	{
		head = *stack_a;
		tail = ft_ndlast(*stack_a);
		if (head != tail)
		{
			while (head->next != NULL && ft_get_chunk(head, right_chunk) != chunk)
				head = head->next;
			while (tail->prev != NULL && ft_get_chunk(tail, right_chunk) != chunk)
				tail = tail->prev;
			if (head == tail)
				ft_move_to_otherstack(stack_a, stack_b, head);
			else if (!tail || ft_get_chunk(tail, right_chunk) != chunk)
				ft_move_to_otherstack(stack_a, stack_b, head);
			else
				ft_dispatch_chunk(stack_a, stack_b, head, tail);
		}
		else
			ft_move_to_otherstack(stack_a, stack_b, head);
		if (ft_stack_size(stack_b) % right_chunk == 0)
			chunk++;
	}
	ft_get_final_stack(stack_a, stack_b);
	return (stack_a);
}

t_data	**ft_sorting(t_data **stack_a, t_data **stack_b)
{
	ft_put_index(stack_a);
	if (ft_stack_size(stack_a) == 2)
		stack_a = ft_sort_2(stack_a);
	else if (ft_stack_size(stack_a) == 3)
		stack_a = ft_sort_3(stack_a);
	else if (ft_stack_size(stack_a) == 4)
		stack_a = ft_sort_4(stack_a, stack_b);
	else if (ft_stack_size(stack_a) == 5)
		stack_a = ft_sort_5(stack_a, stack_b);
	else if (ft_stack_size(stack_a) > 5 && ft_stack_size(stack_a) < 100)
		stack_a = ft_sort_100(stack_a, stack_b, 20);
	else
		stack_a = ft_sort_100(stack_a, stack_b, 45);

	return (stack_a);
}
