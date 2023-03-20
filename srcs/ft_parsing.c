/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:54:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/20 18:19:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	**ft_create_struct(t_data **stack, char **args)
{
	int	index;
	t_data	*new_node;

	if (!args)
		return (0);
	index = 0;
	while (args && args[index])
	{
		new_node = ft_ndnew(ft_atoi(args[index]), index);
		if (!new_node)
			return (0);
		ft_ndadd_back(stack, new_node);
		index++;
	}
	return (stack);
}

t_data	**ft_get_args(t_data **stack_a, int ac, char **av)
{
	int		i;
	char	**args;

	if (!av)
		return (0);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		args = malloc(sizeof(char *) * (ac));
		if (!args)
			return (0);
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
