/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:17:10 by geraudtsers       #+#    #+#             */
/*   Updated: 2023/03/23 15:30:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_2(t_data **stack_a)
{
	int	top;
	int	bottom;

	top = (*stack_a)->data;
	bottom = (*stack_a)->next->data;
	if (top > bottom)
		sa(stack_a);
}

void	ft_sort_3(t_data **stack_a)
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

void	ft_sort_4(t_data **stack_a, t_data **stack_b)
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
	ft_move_front_stack(stack_a, min, 'A');
	pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	ft_sort_5(t_data **stack_a, t_data **stack_b)
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
	ft_move_front_stack(stack_a, max, 'A');
	pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
	ra(stack_a);
}
