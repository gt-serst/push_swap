/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sorting_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:29:02 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/20 18:24:01 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	**ft_simple_swap_to_front(t_data **stack, t_data *elem)
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
	return (stack);
}


void	ft_swap_to_front(t_data **stack, t_data *elem)
{
	if (ft_get_spot(stack, elem) <= (ft_stack_size(stack) / 2))
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

void	ft_swap_to_front_b(t_data **stack, t_data *elem)
{
	if (ft_get_spot(stack, elem) <= (ft_stack_size(stack) / 2))
	{
		while (ft_get_spot(stack, elem) != 0)
			rb(stack);
	}
	else
	{
		while (ft_get_spot(stack, elem) != 0)
			rrb(stack);
	}
}
