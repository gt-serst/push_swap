/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:08:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/24 18:56:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_malloc(char **tab)
{
	int	k;

	k = 0;
	while (tab && tab[k])
	{
		free(tab[k]);
		k++;
	}
	free(tab);
}

int	ft_check_digit(int ac, char **av)
{
	int	i;
	int temp;

	if (ac == 2)
		i = 0;
	else 
		i = 1;
	while (av[i])
	{
		temp = ft_atoi(av[i]);
		if (!ft_isdigit(temp + '0'))
		{
			printf("%d\n", temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_av(int ac, char **av)
{
	char	**args;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!ft_check_digit(ac, args))
		{
			ft_free_malloc(args);
			return (0);
		}
	}
	else
	{
		if (!ft_check_digit(ac, av))
			return (0);
	}
	return (1);
}


