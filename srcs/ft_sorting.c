/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:42 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/22 20:11:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_put_index(t_data **stack)
{
	int		pos;
	t_data	*head;
	t_data	*temp;

	head = *stack;
	while (head)
	{
		pos = 0;
		temp = *stack;
		while (temp)
		{
			if (head->data >= temp->data)
				pos++;
			temp = temp->next;
		}
		head->index = pos;
		head = head->next;
	}
}

int	ft_stack_size(t_data **stack)
{
	int		stack_size;
	t_data	*head;

	stack_size = 0;
	head = *stack;
	while ((*stack))
	{
		*stack = (*stack)->next;
		stack_size++;
	}
	*stack = head;
	return (stack_size);
}

int	ft_get_spot(t_data **stack, t_data *elem)
{
	int		spot;
	t_data	*head;

	spot = 0;
	head = *stack;
	while (head->next)
	{
		if (head->index == elem->index)
			break ;
		spot++;
		head = head->next;
	}
	return (spot);
}

void	ft_sorting(t_data **stack_a, t_data **stack_b)
{
	if (!stack_a)
		return ;
	ft_put_index(stack_a);
	if (ft_stack_size(stack_a) == 2)
		ft_sort_2(stack_a);
	else if (ft_stack_size(stack_a) == 3)
		ft_sort_3(stack_a);
	else if (ft_stack_size(stack_a) == 4)
		ft_sort_4(stack_a, stack_b);
	else if (ft_stack_size(stack_a) == 5)
		ft_sort_5(stack_a, stack_b);
	else if (ft_stack_size(stack_a) > 5 && ft_stack_size(stack_a) <= 100)
		ft_sort_100(stack_a, stack_b, 20);
	else
		ft_sort_100(stack_a, stack_b, 45);
}
