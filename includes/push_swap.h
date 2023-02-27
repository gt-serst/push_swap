/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:51 by gt-serst          #+#    #+#             */
/*   Updated: 2023/02/27 21:22:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int				data;
	struct s_data	*next;
}				t_data;

int			ft_check_av(int ac, char **av);
int			ft_check_digit(int ac, char **av);
int			ft_check_intoverflow(int ac, char **av);
int			ft_check_double(int ac, char **av);
long long	ft_atol(const char *str);
void		ft_free_malloc(char	**tab);
t_data		**ft_get_args(t_data **stack_a, int ac, char **av);
t_data		**ft_create_struct(t_data **stack_a, char **args);
t_data		*ft_ndnew(int data);
void		ft_ndadd_back(t_data **stack_a, t_data *elem);
void		ft_ndclear(t_data **stack);
void		sa(t_data **stack_a);
void		sb(t_data **stack_b);
void		ss(t_data **stack_a, t_data **stack_b);
void		pa(t_data **stack_a, t_data **stack_b);
void		pb(t_data **stack_b, t_data **stack_a);
void		swap(t_data **stack);
void		push(t_data **stack_src, t_data **stack_dst);

#endif
