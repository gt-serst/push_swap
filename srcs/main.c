/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/08 17:25:49 by gt-serst         ###   ########.fr       */
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
	
	printf("stack_a : %d, stack_a->next : %d, stack_a->prev: %d\n", (*stack_a)->next->next->data, (*stack_a)->next->next->next->data, (*stack_a)->next->next->prev->data);
	
	sa(stack_a);
	printf("Linked list A after SA operation:\n");
	ft_print_list(*stack_a);
	
	printf("stack_a : %d, stack_a->next : %d, stack_a->prev: %d\n", (*stack_a)->next->next->data, (*stack_a)->next->next->next->data, (*stack_a)->next->next->prev->data);

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	printf("Linked list A after PB PB PB operation:\n");
	ft_print_list(*stack_a);

	printf("stack_a : %d, stack_a->next : %d, stack_a->prev: %d\n", (*stack_a)->next->data, (*stack_a)->next->next->data, (*stack_a)->next->prev->data);

	printf("Linked list B after PB PB PB:\n");
	ft_print_list(*stack_b);

	printf("stack_a : %d, stack_a->next : %d, stack_a->prev: %d\n", (*stack_a)->next->data, (*stack_a)->next->next->data, (*stack_a)->next->prev->data);
	printf("stack_b : %d, stack_b->next : %d, stack_b->prev: %d\n", (*stack_b)->next->data, (*stack_b)->next->next->data, (*stack_b)->next->prev->data);
	pb(stack_a, stack_b);
	ft_print_list(*stack_a);
	ft_print_list(*stack_b);
	printf("stack_a->next : %d, stack_a->next->prev : %d", (*stack_a)->next->data, (*stack_a)->next->prev->data);
	printf("stack_b : %d, stack_b->next : %d, stack_b->prev: %d\n", (*stack_b)->next->next->data, (*stack_b)->next->next->next->data, (*stack_b)->next->next->prev->data);
	
	return (0);
/*
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

	stack_a = ft_sort_5(stack_a, stack_b);
	printf("Stack A:");
	ft_print_list(*stack_a);
	printf("Stack B:");
	ft_print_list(*stack_b);
*/
	stack_a = ft_sorting(stack_a, stack_b);
	//ft_print_list(*stack_a);
}
