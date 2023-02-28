 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:03:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/27 21:24:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_data **stack)
{
	t_data	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_data **stack_src, t_data **stack_dst)
{
	t_data	*temp;

	temp = (*stack_src)->next;
	(*stack_src)->next = (*stack_dst);
	(*stack_dst) = (*stack_src);
	(*stack_src) = temp;
}

void	move_to_end (t_data **stack)
{
	t_data	*head;
	t_data	*tail;

	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	move_to_front(t_data **stack)
{
	t_data	*before_tail;
	t_data	*tail;

	tail = *stack;
	while (tail->next != NULL)
	{
		before_tail = tail;
		tail = tail->next;
	}
	before_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rrr(t_data **stack_a, t_data **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
