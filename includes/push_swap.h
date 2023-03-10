/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:51 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/10 23:34:09 by gt-serst         ###   ########.fr       */
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
	int		data;
	int		index;
	struct s_data	*next;
	struct s_data	*prev;
}				t_data;

int		ft_check_av(int ac, char **av);
int		ft_check_digit(int ac, char **av);
int		ft_check_intoverflow(int ac, char **av);
int		ft_check_double(int ac, char **av);
long long	ft_atol(const char *str);
void		ft_free_malloc(char	**tab);
t_data		**ft_get_args(t_data **stack_a, int ac, char **av);
t_data		**ft_create_struct(t_data **stack_a, char **args);
t_data		*ft_ndnew(int data, int index);
void		ft_ndadd_back(t_data **stack_a, t_data *elem);
t_data		*ft_ndlast(t_data *head);
void		ft_ndclear(t_data **stack);
void		sa(t_data **stack_a);
void		sb(t_data **stack_b);
void		ss(t_data **stack_a, t_data **stack_b);
void		pa(t_data **stack_b, t_data **stack_a);
void		pb(t_data **stack_a, t_data **stack_b);
void		ra(t_data **stack_a);
void		rb(t_data **stack_b);
void		rr(t_data **stack_a, t_data **stack_b);
void		rra(t_data **stack_a);
void		rrb(t_data **stack_b);
void		rrr(t_data **stack_a, t_data **stack_b);
void		swap(t_data **stack);
void		push(t_data **stack_src, t_data **stack_dst);
void		move_to_end(t_data **stack);
void		move_to_front(t_data **stack);
t_data		**ft_sorting(t_data **stack_a, t_data **stack_b);
void		ft_put_index(t_data **stack);
int		ft_stack_size(t_data **stack);
t_data		**ft_sort_2(t_data **stack_a);
t_data		**ft_sort_3(t_data **stack_a);
t_data		**ft_sort_4(t_data **stack_a, t_data **stack_b);
t_data		**ft_sort_5(t_data **stack_a, t_data **stack_b);
t_data		**ft_sort_100(t_data **stack_a, t_data **stack_b);
int		ft_get_max(t_data **stack);
int		ft_get_min(t_data **stack);
t_data		**ft_simple_swap_to_front(t_data **stack, t_data *elem);
int		ft_get_spot(t_data **stack, t_data *elem);
int		ft_get_chunk(t_data *elem);
void		ft_dispatch_chunk(t_data **stack_a, t_data **stack_b, t_data *head, t_data *tail);
int			ft_get_moves_to_top(int spot, int stack_size);
void		ft_move_to_otherstack(t_data **stack_a, t_data **stack_b, t_data *hold);
void		ft_is_candidate(t_data **stack_a, t_data **stack_b, t_data *restriction);
void		ft_swap_to_front(t_data **stack, t_data *elem);
void		ft_swap_to_front_b(t_data **stack, t_data *elem);
void		ft_get_final_stack(t_data **stack_a, t_data **stack_b);

void		ft_print_list(t_data *head);

#endif
