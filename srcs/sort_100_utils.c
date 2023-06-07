/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:39:41 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_moves_to_top(int spot, int stack_size)
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

void	put_at_right_place(t_data **stack_b, t_data *hold)
{
	int		pos;

	if (is_max(stack_b, hold))
	{
		pos = get_max_pos(stack_b, hold);
		adjust_stackmax(stack_b, pos);
	}
	else if (is_min(stack_b, hold))
	{
		pos = get_min_pos(stack_b, hold);
		adjust_stackmin(stack_b, pos);
	}
	else
		check_index(stack_b, hold);
}

void	move_to_otherstack(t_data **stack_a, t_data **stack_b, t_data *hold)
{
	move_front_stack(stack_a, hold, 1);
	if (!*stack_b)
	{
		pb(stack_a, stack_b);
		return ;
	}
	put_at_right_place(stack_b, hold);
	pb(stack_a, stack_b);
}

void	dispatch_chunk(t_data **stack_a, t_data **stack_b,
				t_data *top, t_data *bottom)
{
	int	top_spot;
	int	bottom_spot;
	int	stack_size;

	top_spot = get_spot(stack_a, top);
	bottom_spot = get_spot(stack_a, bottom);
	stack_size = get_stack_size(stack_a);
	if (get_moves_to_top(top_spot, stack_size)
		<= get_moves_to_top(bottom_spot, stack_size))
		move_to_otherstack(stack_a, stack_b, top);
	else
		move_to_otherstack(stack_a, stack_b, bottom);
}
