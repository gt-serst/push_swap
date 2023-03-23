/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:54:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/23 14:52:56 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_create_list(t_data **stack, int ac, char **av)
{
	int		i;
	t_data	*new_node;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av && av[i])
	{
		new_node = ft_ndnew(ft_atoi(av[i]));
		if (!new_node)
			return (0);
		ft_ndadd_back(stack, new_node);
		i++;
	}
	return (1);
}

int	ft_get_av(t_data **stack_a, int ac, char **av)
{
	char	**args;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (*args && ft_create_list(stack_a, ac, args))
		{
			ft_free_malloc(args);
			return (1);
		}
	}
	else
	{
		if (ft_create_list(stack_a, ac, av))
			return (1);
	}
	if (ac == 2)
		ft_free_malloc(args);
	return (0);
}
