/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:26:00 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pos_from_bottom(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*tail;

	pos = 0;
	tail = ndlast(*stack);
	while (tail && elem->index > tail->index)
	{
		pos++;
		tail = tail->prev;
	}
	return (pos);
}

int	get_pos_from_top(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*head;

	pos = 0;
	head = *stack;
	while (head && elem->index < head->index)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}

int	get_max_pos(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*head;

	pos = 0;
	head = *stack;
	while (head->next && elem->index > head->index)
	{
		if (head->data < head->next->data)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}

int	get_min_pos(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*head;

	pos = 0;
	head = *stack;
	while (head->next && elem->index < head->index)
	{
		if (head->data < head->next->data)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}

void	check_index(t_data **stack_b, t_data *hold)
{
	int		pos;
	t_data	*head;

	head = *stack_b;
	if (hold->index > head->index)
	{
		pos = get_pos_from_bottom(stack_b, hold);
		pos = (get_stack_size(stack_b) - pos);
		adjust_stack(stack_b, hold, pos);
	}
	else
	{
		pos = get_pos_from_top(stack_b, hold);
		adjust_stack(stack_b, hold, pos);
	}
}
