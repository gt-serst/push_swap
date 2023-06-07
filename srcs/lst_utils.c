/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:18:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:51:53 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*ndnew(int data)
{
	t_data	*elem;

	elem = malloc(sizeof(t_data));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_data	*ndlast(t_data *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ndadd_back(t_data **stack, t_data *elem)
{
	t_data	*temp;

	if (!stack || !elem)
		return ;
	if (*stack)
	{
		temp = ndlast(*stack);
		temp->next = elem;
		elem->prev = temp;
	}
	else
		*stack = elem;
}

void	ndsclear(t_data **stack)
{
	t_data	*head;
	t_data	*temp;

	if (!stack)
		return ;
	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}
