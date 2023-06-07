/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:35:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_final_stack(t_data **stack_a, t_data **stack_b)
{
	int		count;
	int		stack_size;
	t_data	*head;
	t_data	*temp;

	count = 0;
	stack_size = get_stack_size(stack_b);
	head = *stack_b;
	while (head)
	{
		temp = head;
		while (temp)
		{
			if (temp->index == (stack_size - count))
			{
				move_front_stack(stack_b, temp, 2);
				pa(stack_b, stack_a);
				break ;
			}
			temp = temp->next;
		}
		count++;
		head = *stack_b;
	}
}

int	get_chunk(t_data *elem, int right_chunk)
{
	int	chunk;

	if (elem->index % right_chunk == 0)
		chunk = (elem->index / right_chunk);
	else
		chunk = ((elem->index) / right_chunk) + 1;
	return (chunk);
}

void	sort_100(t_data **stack_a, t_data **stack_b, int right_chunk)
{
	t_data	*head;
	t_data	*tail;
	int		chunk;
	int		chunk_max;

	chunk = 1;
	chunk_max = (get_stack_size(stack_a) / right_chunk) + 1;
	while (*stack_a && chunk <= chunk_max)
	{
		head = *stack_a;
		tail = ndlast(*stack_a);
		while (head->next && get_chunk(head, right_chunk) != chunk)
			head = head->next;
		while (tail->prev && get_chunk(tail, right_chunk) != chunk)
			tail = tail->prev;
		dispatch_chunk(stack_a, stack_b, head, tail);
		if (get_stack_size(stack_b) % right_chunk == 0)
			chunk++;
	}
	get_final_stack(stack_a, stack_b);
}
