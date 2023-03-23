/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:39:41 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/23 16:58:03 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_put_at_right_place(t_data **stack_b, t_data *hold)
{
	int		pos;

	if (ft_is_max(stack_b, hold))
	{
		pos = ft_get_max_pos(stack_b, hold);
		ft_adjust_stackmax(stack_b, pos);
	}
	else if (ft_is_min(stack_b, hold))
	{
		pos = ft_get_min_pos(stack_b, hold);
		ft_adjust_stackmin(stack_b, pos);
	}
	else
		ft_check_index(stack_b, hold);
}

void	ft_move_to_otherstack(t_data **stack_a, t_data **stack_b, t_data *hold)
{
	ft_move_front_stack(stack_a, hold, 1);
	if (!*stack_b)
	{
		pb(stack_a, stack_b);
		return ;
	}
	ft_put_at_right_place(stack_b, hold);
	pb(stack_a, stack_b);
}

void	ft_dispatch_chunk(t_data **stack_a, t_data **stack_b,
				t_data *top, t_data *bottom)
{
	int	top_spot;
	int	bottom_spot;
	int	stack_size;

	top_spot = ft_get_spot(stack_a, top);
	bottom_spot = ft_get_spot(stack_a, bottom);
	stack_size = ft_stack_size(stack_a);
	if (ft_get_moves_to_top(top_spot, stack_size)
		<= ft_get_moves_to_top(bottom_spot, stack_size))
		ft_move_to_otherstack(stack_a, stack_b, top);
	else
		ft_move_to_otherstack(stack_a, stack_b, bottom);
}
