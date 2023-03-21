/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/21 16:51:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list(t_data *head)
{
	while (head)
	{
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_data	**stack_a;
	t_data	**stack_b;

	if (ac < 2)
		return (-1);
	if (!ft_check_av(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = malloc(sizeof(t_data *));
	stack_b = malloc(sizeof(t_data *));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	stack_a = ft_get_args(stack_a, ac, av);
	if (!stack_a)
	{
		ft_ndclear(stack_a);
		system("leaks push_swap");
		return (0);
	}
	ft_sorting(stack_a, stack_b);
	return (0);
}
