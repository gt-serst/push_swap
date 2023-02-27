/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:03:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/27 21:24:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_data **stack)
{
	t_data	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void push(t_data **stack_src, t_data **stack_dst)
{
	t_data	*temp;
	
	temp = (*stack_src)->next;
	(*stack_src)->next = (*stack_dst);
	(*stack_dst) = (*stack_src);
	(*stack_src) = temp;
}
