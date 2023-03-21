/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:08:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/21 17:19:44 by gt-serst         ###   ########.fr       */
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

int	ft_check_double(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_intoverflow(int ac, char **av)
{
	int			i;
	long long	current_digit;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		current_digit = ft_atol(av[i]);
		if (current_digit > INT_MAX || current_digit < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_digit(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
			return (0);
		else
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
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
		if (!ft_check_digit(ac, args) || !ft_check_intoverflow(ac, args)
			|| !ft_check_double(ac, args))
		{
			ft_free_malloc(args);
			return (0);
		}
	}
	else
	{
		if (!ft_check_digit(ac, av) || !ft_check_intoverflow(ac, av)
			|| !ft_check_double(ac, av))
			return (0);
	}
	return (1);
}
