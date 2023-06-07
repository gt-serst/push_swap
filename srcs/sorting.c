/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:42 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_index(t_data **stack)
{
	int		pos;
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

int	get_stack_size(t_data **stack)
{
	int		stack_size;
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

int	get_spot(t_data **stack, t_data *elem)
{
	int		spot;
	t_data	*head;

	spot = 0;
	head = *stack;
	while (head->next)
	{
		if (head->index == elem->index)
			break ;
		spot++;
		head = head->next;
	}
	return (spot);
}

void	move_front_stack(t_data **stack, t_data *elem, int idx)
{
	if (get_spot(stack, elem) <= (get_stack_size(stack) / 2))
	{
		while (get_spot(stack, elem) != 0)
		{
			if (idx == 1)
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (get_spot(stack, elem) != 0)
		{
			if (idx == 1)
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	sorting(t_data **stack_a, t_data **stack_b)
{
	put_index(stack_a);
	if (!is_sorted(stack_a))
	{
		if (get_stack_size(stack_a) == 2)
			sort_2(stack_a);
		else if (get_stack_size(stack_a) == 3)
			sort_3(stack_a);
		else if (get_stack_size(stack_a) == 4)
			sort_4(stack_a, stack_b);
		else if (get_stack_size(stack_a) == 5)
			sort_5(stack_a, stack_b);
		else if (get_stack_size(stack_a) > 5 && get_stack_size(stack_a) <= 100)
			sort_100(stack_a, stack_b, 20);
		else
			sort_100(stack_a, stack_b, 45);
	}
}
