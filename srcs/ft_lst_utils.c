/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:18:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/27 20:49:22 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*ft_ndnew(int data, int index)
{
	t_data	*elem;

	elem = malloc(sizeof(t_data));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->index = index;
	//printf("Index:%d\n", elem->index);
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_data	*ft_ndlast(t_data *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_ndadd_back(t_data **stack, t_data *elem)
{
	t_data	*temp;

	if (!stack || !elem)
		return ;
	if (*stack)
	{
		temp = ft_ndlast(*stack);
		temp->next = elem;
		elem->prev = temp;
	}
	else
		*stack = elem;
}

/*
static void	ft_nddelone(t_data *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del((char *)lst->data);
	free(lst);
	lst = NULL;
}

static void	ft_del(void	*content)
{
	free(content);
}
*/

void	ft_ndclear(t_data **stack)
{
	t_data	*head;
	t_data	*temp;

	if (!stack)
		return ;
	head = *stack;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	*stack = NULL;
}
