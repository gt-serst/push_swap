/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:35:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:55 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_final_stack(t_data **stack_a, t_data **stack_b)
{
	int		count;
	int		stack_size;
	t_data	*head;
	t_data	*temp;

	count = 0;
	stack_size = ft_stack_size(stack_b);
	head = *stack_b;
	while (head)
	{
		temp = head;
		while (temp)
		{
			if (temp->index == (stack_size - count))
			{
				ft_print_list(*stack_b);
				printf("elem:%d\n", temp->data);
				printf("elem->index:%d\n", temp->index);
				ft_swap_to_front(stack_b, temp);
				pa(stack_b, stack_a);
				break ;
			}
			temp = temp->next;
		}
		count++;
		head = *stack_b;
	}
}
