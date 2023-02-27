/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/27 21:24:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_list(t_data *head)
{
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int	main(int ac, char **av)
{
	t_data	**stack_a;
	t_data	**stack_b;

	if (!ft_check_av(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = malloc(sizeof(t_data *));
	stack_b = malloc(sizeof(t_data *));
	if (!stack_a || !stack_b)
		return (0);
	stack_a = ft_get_args(stack_a, ac, av);
	if (!stack_a)
	{
		ft_ndclear(stack_a);
		system("leaks push_swap");
		return (0);
	}

	printf("Initial linked list A:\n");
	ft_print_list(*stack_a);

	sa(stack_a);
	printf("Linked list A after SA operation:\n");
	ft_print_list(*stack_a);

	pb(stack_b, stack_a);
	printf("Linked list A after PB operation:\n");
	ft_print_list(*stack_a);
	
	printf("Linked list B after PB:\n");
	ft_print_list(*stack_b);

	pa(stack_a, stack_b);
	printf("Linked list B after PA:\n");
	ft_print_list(*stack_b);

	printf("Linked list A after PA:\n");
	ft_print_list(*stack_a);
}
