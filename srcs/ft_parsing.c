/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:54:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/24 18:56:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	**ft_create_struct(t_data **stack, char **args)
{
	int		i;

	if (!args)
		return (0);
	i = 0;
	while (args && args[i])
	{
		ft_ndadd_back(stack, ft_ndnew(ft_atoi(args[i])));
		i++;
	}
	return (stack);
}

t_data	**ft_get_args(t_data **stack_a, int ac, char **av)
{
	int		i;
	char	**args;

	if (!av)
		return (NULL);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		args = malloc(sizeof(char*) * (ac));
		if (!args)
			return (NULL);
		args[ac - 1] = 0;
		i = 0;
		while (av[i + 1])
		{
			args[i] = ft_strdup(av[i + 1]);
			i++;
		}
	}
	stack_a = ft_create_struct(stack_a, args);	
	ft_free_malloc(args);
	return (stack_a);
}
