/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:27:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:24 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_max(t_data **stack, t_data *elem)
{
	t_data	*head;

	head = *stack;
	while (head)
	{
		if (elem->index < head->index)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_min(t_data **stack, t_data *elem)
{
	t_data	*head;

	head = *stack;
	while (head)
	{
		if (elem->index > head->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	adjust_stack(t_data **stack, t_data *hold, int pos)
{
	t_data	*head;
	t_data	*tail;

	head = *stack;
	tail = ndlast(*stack);
	while (head && (hold->index < head->index || hold->index > tail->index))
	{
		if (pos <= get_stack_size(stack) / 2)
			rb(stack);
		else
			rrb(stack);
		head = *stack;
		tail = ndlast(*stack);
	}
}

void	adjust_stackmax(t_data **stack, int pos)
{
	t_data	*tail;

	tail = ndlast(*stack);
	while (!is_min(stack, tail))
	{
		if (pos <= get_stack_size(stack) / 2)
			rb(stack);
		else
			rrb(stack);
		tail = ndlast(*stack);
	}
}

void	adjust_stackmin(t_data **stack, int pos)
{
	t_data	*head;

	head = *stack;
	while (!is_max(stack, head))
	{
		if (pos <= get_stack_size(stack) / 2)
			rb(stack);
		else
			rrb(stack);
		head = *stack;
	}
}
