/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:29:10 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/22 20:17:17 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_move_front_stack(t_data **stack, t_data *elem)
{
	if (ft_get_spot(stack, elem) <= 3)
	{
		while (ft_get_spot(stack, elem) != 0)
			ra(stack);
	}
	else
	{
		while (ft_get_spot(stack, elem) != 0)
			rra(stack);
	}
}

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
	if (top < middle && middle > bottom && bottom < top)
		rra(stack_a);
	if (top > middle && middle < bottom && bottom < top)
		ra(stack_a);
	if (top > middle && middle > bottom && bottom < top)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (top < middle && middle > bottom && bottom > top)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	ft_sort_4(t_data **stack_a, t_data **stack_b)
{
	t_data	*head;
	t_data	*elem_min;

	head = *stack_a;
	elem_min = NULL;
	while (head)
	{
		if (head->index == 1)
		{
			elem_min = head;
			break ;
		}
		head = head->next;
	}
	ft_move_front_stack(stack_a, elem_min);
	pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	ft_sort_5(t_data **stack_a, t_data **stack_b)
{
	t_data	*head;
	t_data	*elem_max;
	t_data	*elem_min;

	head = *stack_a;
	elem_max = NULL;
	elem_min = NULL;
	while (head)
	{
		if (head->index == 5)
			elem_max = head;
		if (head->index == 1)
			elem_min = head;
		head = head->next;
	}
	ft_move_front_stack(stack_a, elem_max);
	pb(stack_a, stack_b);
	ft_move_front_stack(stack_a, elem_min);
	pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	ra(stack_a);
}
