/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:18:45 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/10 15:48:01 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:03:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/08 16:03:05 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_data **stack)
{
	t_data	*left;
	t_data	*right;
	
	if (!(*stack))
			return ;
	left = (*stack);
	right = (*stack)->next;
	left->prev = right;
	left->next = right->next;
	right->next->prev = left;
	right->next = left;
	right->prev = NULL;
	(*stack) = right;
}

void	push(t_data **stack_src, t_data **stack_dst)
{
	t_data	*temp;

	if (!(*stack_src))
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = (*stack_dst);
	if (*stack_dst != NULL)
		(*stack_dst)->prev = (*stack_src);
	(*stack_dst) = (*stack_src);
	(*stack_src) = temp;
	if (*stack_src != NULL)
		(*stack_src)->prev = NULL;
}

void	move_to_end (t_data **stack)
{
	t_data	*head;
	t_data	*tail;

	if (!(*stack))
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	*stack = head->next;
	(*stack)->prev = NULL;
	head->next = NULL;
	head->prev = tail;
	tail->next = head;
}

void	move_to_front(t_data **stack)
{
	t_data	*before_tail;
	t_data	*tail;

	if (!(*stack))
		return ;
	tail = *stack;
	while (tail->next != NULL)
	{
		before_tail = tail;
		tail = tail->next;
	}
	before_tail->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}

void	rrr(t_data **stack_a, t_data **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
