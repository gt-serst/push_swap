/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/30 14:44:13 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_data **stack)
{
	t_data	*head;

	head = *stack;
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	**stack_a;
	t_data	**stack_b;

	if (ac < 2)
		return (1);
	ft_check_av(ac, av);
	stack_a = malloc(sizeof(t_data *));
	stack_b = malloc(sizeof(t_data *));
	if (!stack_a && !stack_b)
		return (1);
	*stack_a = NULL;
	*stack_b = NULL;
	if (!ft_get_av(stack_a, ac, av))
	{
		ft_ndsclear(stack_a);
		ft_ndsclear(stack_b);
		return (1);
	}
	ft_sorting(stack_a, stack_b);
	ft_ndsclear(stack_a);
	ft_ndsclear(stack_b);
	return (0);
}
