/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:17:10 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 16:54:35 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_data **stack_a)
{
	int	top;
	int	bottom;

	top = (*stack_a)->data;
	bottom = (*stack_a)->next->data;
	if (top > bottom)
		sa(stack_a);
}

void	sort_3(t_data **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->data;
	middle = (*stack_a)->next->data;
	bottom = (*stack_a)->next->next->data;
	if (top > middle && middle < bottom && bottom > top)
		sa(stack_a);
	if (top > middle && middle > bottom && bottom < top)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (top < middle && middle > bottom && bottom < top)
		rra(stack_a);
	if (top < middle && middle > bottom && bottom > top)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (top > middle && middle < bottom && bottom < top)
		ra(stack_a);
}

void	sort_4(t_data **stack_a, t_data **stack_b)
{
	t_data	*head;
	t_data	*min;

	head = *stack_a;
	min = *stack_a;
	while (head)
	{
		if (head->data < min->data)
			min = head;
		head = head->next;
	}
	move_front_stack(stack_a, min, 1);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_data **stack_a, t_data **stack_b)
{
	t_data	*head;
	t_data	*max;

	head = *stack_a;
	max = *stack_a;
	while (head)
	{
		if (head->data > max->data)
			max = head;
		head = head->next;
	}
	move_front_stack(stack_a, max, 1);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
	ra(stack_a);
}
