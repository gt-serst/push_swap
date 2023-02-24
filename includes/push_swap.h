/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:51 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/24 18:42:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int				data;
	struct s_data	*next;
}				t_data;

int		ft_check_av(int ac, char **av);
int		ft_check_digit(int ac, char **av);
void	ft_free_malloc(char	**tab);
t_data	**ft_get_args(t_data **stack_a, int ac, char **av);
t_data	**ft_create_struct(t_data **stack_a, char **args);
t_data	*ft_ndnew(int data);
void	ft_ndadd_back(t_data **stack_a, t_data *elem);

#endif
