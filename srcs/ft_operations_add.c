/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:28:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/22 19:09:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_data **stack_a)
{
	if (ft_stack_size(stack_a) < 2)
		return ;
	move_to_end(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data **stack_b)
{
	if (ft_stack_size(stack_b) < 2)
		return ;
	move_to_end(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	if (ft_stack_size(stack_a) < 2 || ft_stack_size(stack_b) < 2)
		return ;
	move_to_end(stack_a);
	move_to_end(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_data **stack_a)
{
	if (ft_stack_size(stack_a) < 2)
		return ;
	move_to_front(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data **stack_b)
{
	if (ft_stack_size(stack_b) < 2)
		return ;
	move_to_front(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
