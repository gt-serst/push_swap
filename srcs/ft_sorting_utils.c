/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:28:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/20 19:28:06 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_max(t_data **stack)
{
	int	max;
	t_data	*head;
	t_data	*next;

	head = *stack;
	max = (*stack)->data;
	while ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		if (max < next->data)
			max = next->data;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (max);
}

int	ft_get_min(t_data **stack)
{
	int	min;
	t_data	*head;
	t_data	*next;

	head = *stack;
	min = (*stack)->data;
	while ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		if (min > next->data)
			min = next->data;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (min);
}

int	ft_get_spot(t_data **stack, t_data *elem)
{
	int		spot;
	t_data	*head;

	spot = 0;
	head = *stack;
	while (head->next != NULL)
	{
		if (head->data == elem->data)
			break ;
		spot++;
		head = head->next;
	}
	return (spot);
}

int	ft_get_chunk(t_data *elem, int right_chunk)
{
	int	chunk;

	if (elem->index % right_chunk == 0)
		chunk = (elem->index / right_chunk);
	else
		chunk = ((elem->index) / right_chunk) + 1;
	return (chunk);
}

int	ft_get_moves_to_top(int spot, int stack_size)
{
	int	moves_to_top;
	int	middle_spot;

	middle_spot = (stack_size / 2);
	if (spot <= middle_spot)
		moves_to_top = spot;
	else
		moves_to_top = (stack_size) - (spot);
	return (moves_to_top);
}

void	ft_dispatch_chunk(t_data **stack_a, t_data **stack_b, t_data *top, t_data *bottom)
{
	int		top_spot;
	int		bottom_spot;
	int		stack_size;

	top_spot = ft_get_spot(stack_a, top);
	bottom_spot = ft_get_spot(stack_a, bottom);
	stack_size = ft_stack_size(stack_a);
	if (ft_get_moves_to_top(top_spot, stack_size) <= ft_get_moves_to_top(bottom_spot, stack_size))
		ft_move_to_otherstack(stack_a, stack_b, top);
	else
		ft_move_to_otherstack(stack_a, stack_b, bottom);
}

void	ft_move_to_otherstack(t_data **stack_a, t_data **stack_b, t_data *hold)
{
	ft_swap_to_front(stack_a, hold);
	if (*stack_b == NULL)
	{
		pb(stack_a, stack_b);
		return ;
	}
	ft_put_at_right_place(stack_b, hold);
	pb(stack_a, stack_b);
}

int	ft_is_max(t_data **stack, t_data *elem)
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

int	ft_is_min(t_data **stack, t_data *elem)
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

int	ft_get_pos_from_bottom(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*tail;

	pos = 0;
	tail = ft_ndlast(*stack);
	while (tail && elem->data > tail->data)
	{
		pos++;
		tail = tail->prev;
	}
	return (pos);
}

int	ft_get_pos_from_top(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*head;

	pos = 0;
	head = *stack;
	while (head && elem->data < head->data)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}

int	ft_get_max_pos(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*head;

	pos = 0;
	head = *stack;
	while (head->next != NULL && elem->data > head->data)
	{
		if (head->data < head->next->data)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}

int	ft_get_min_pos(t_data **stack, t_data *elem)
{
	int		pos;
	t_data	*head;

	pos = 0;
	head = *stack;
	while (head->next != NULL && elem->data < head->data)
	{
		if (head->data < head->next->data)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}

void	ft_swap_elem(t_data **stack, t_data *hold, int pos)
{
	t_data	*head;
	t_data	*tail;

	head = *stack;
	tail = ft_ndlast(*stack);
	while (head && (hold->index < head->index || hold->index > tail->index))
	{
		if (pos <= ft_stack_size(stack) / 2)
			rb(stack);
		else
			rrb(stack);
		head = *stack;
		tail = ft_ndlast(*stack);
	}
}

void	ft_swap_max(t_data **stack, int pos)
{
	t_data	*tail;

	tail = ft_ndlast(*stack);
	while(!ft_is_min(stack, tail))
	{
		if (pos <= ft_stack_size(stack) / 2)
			rb(stack);
		else
			rrb(stack);
		tail = ft_ndlast(*stack);
	}
}

void	ft_swap_min(t_data **stack, int pos)
{
	t_data	*head;

	head = *stack;
	while (!ft_is_max(stack, head))
	{
		if (pos <= ft_stack_size(stack) / 2)
			rb(stack);
		else
			rrb(stack);
		head = *stack;
	}
}

void	ft_put_at_right_place(t_data **stack_b, t_data *hold)
{
	int		pos;
	t_data	*head;

	head = *stack_b;
	if (ft_is_max(stack_b, hold))
	{
		pos = ft_get_max_pos(stack_b, hold);
		ft_swap_max(stack_b, pos);
	}
	else if (ft_is_min(stack_b, hold))
	{
		pos = ft_get_min_pos(stack_b, hold);
		ft_swap_min(stack_b, pos);
	}
	else
	{
		if (hold->index > head->index)
		{
			pos = ft_get_pos_from_bottom(stack_b, hold);
			pos = ft_stack_size(stack_b) - pos;
			ft_swap_elem(stack_b, hold, pos);
		}
		else
		{
			pos = ft_get_pos_from_top(stack_b, hold);
			ft_swap_elem(stack_b, hold, pos);
		}
	}
}
