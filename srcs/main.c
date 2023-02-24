/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/24 18:56:31 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_data	*head;
	t_data	**stack_a;
	t_data	**stack_b;

	if (!ft_check_av(ac, av))
		return (0);
	stack_a = malloc(sizeof(t_data*));
	stack_b = malloc(sizeof(t_data*));
	if (!stack_a || !stack_b)
		return (0);
	stack_a = ft_get_args(stack_a, ac, av);
	if (!stack_a)
		return (0);
	head = *stack_a;
	while (head)
	{
		printf("%d", head->data);
		head = head->next;
	}
}
