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

void	ft_print_list(t_data *head)
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
	//int	max;
	//int	min;

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

	printf("Initial linked list A:\n");
	ft_print_list(*stack_a);
/*
	sa(stack_a);
	printf("Linked list A after SA operation:\n");
	ft_print_list(*stack_a);

	pb(stack_a, stack_b);
	printf("Linked list A after PB operation:\n");
	ft_print_list(*stack_a);
	
	printf("Linked list B after PB:\n");
	ft_print_list(*stack_b);

	pa(stack_b, stack_a);
	printf("Linked list B after PA:\n");
	ft_print_list(*stack_b);

	printf("Linked list A after PA:\n");
	ft_print_list(*stack_a);

	ra(stack_a);
	printf("Linked list A after RA:\n");
	ft_print_list(*stack_a);

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	rb(stack_b);
	printf("Linked list B after PB PB PB RB:\n");
	ft_print_list(*stack_b);

	printf("Linked list A after PB PB PB:\n");
	ft_print_list(*stack_a);

	rr(stack_a, stack_b);
	printf("Linked list A and B after RR:\n");
	ft_print_list(*stack_a);
	printf("\n");
	ft_print_list(*stack_b);

	rrb(stack_b);
	printf("Linked list B after RRB:\n");
	ft_print_list(*stack_b);

	rra(stack_a);
	printf("Linked list A after RRA:\n");
	ft_print_list(*stack_a);

	rrr(stack_a, stack_b);
	printf("Linked list A and B after RRR:\n");
	ft_print_list(*stack_a);
	printf("\n");
	ft_print_list(*stack_b);

	max = ft_find_max(stack_a);
	printf("%d\n", max);
	min = ft_find_min(stack_a);
	printf("%d\n", min);
*/
	stack_a = ft_sort_5(stack_a, stack_b);
	printf("Stack A:");
	ft_print_list(*stack_a);
	printf("Stack B:");
	ft_print_list(*stack_b);
}
