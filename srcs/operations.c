/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:00:22 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data **stack_a)
{
	if (get_stack_size(stack_a) < 2)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data **stack_b)
{
	if (get_stack_size(stack_b) < 2)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data **stack_a, t_data **stack_b)
{
	if (get_stack_size(stack_a) < 2 || get_stack_size(stack_b) < 2)
		return ;
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_data **stack_b, t_data **stack_a)
{
	if (get_stack_size(stack_b) == 0)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data **stack_a, t_data **stack_b)
{
	if (get_stack_size(stack_a) == 0)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
