/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:51 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:49:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int				data;
	int				index;
	struct s_data	*next;
	struct s_data	*prev;
}				t_data;

void		check_av(int ac, char **av);
int			check_digit(int ac, char **av);
int			check_intoverflow(int ac, char **av);
int			check_double(int ac, char **av);
long long	ft_atol(const char *str);
void		ft_free_malloc(char	**str);
void		ft_error(char *s);
int			get_av(t_data **stack_a, int ac, char **av);
int			create_list(t_data **stack_a, int ac, char **av);
t_data		*ndnew(int data);
void		ndadd_back(t_data **stack_a, t_data *elem);
t_data		*ndlast(t_data *head);
void		ndsclear(t_data **stack);
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
int			is_sorted(t_data **stack);
void		sorting(t_data **stack_a, t_data **stack_b);
void		put_index(t_data **stack);
int			get_stack_size(t_data **stack);
void		sort_2(t_data **stack_a);
void		sort_3(t_data **stack_a);
void		sort_4(t_data **stack_a, t_data **stack_b);
void		sort_5(t_data **stack_a, t_data **stack_b);
void		sort_100(t_data **stack_a, t_data **stack_b, int right_chunk);
int			get_spot(t_data **stack, t_data *elem);
int			get_chunk(t_data *elem, int right_chunk);
void		move_front_stack(t_data **stack, t_data *elem, int idx);
void		dispatch_chunk(t_data **stack_a, t_data **stack_b,
				t_data *head, t_data *tail);
int			get_moves_to_top(int spot, int stack_size);
void		move_to_otherstack(t_data **stack_a,
				t_data **stack_b, t_data *hold);
void		put_at_right_place(t_data **stack_b, t_data *hold);
void		check_index(t_data **stack_b, t_data *hold);
int			is_max(t_data **stack, t_data *elem);
int			is_min(t_data **stack, t_data *elem);
int			get_pos_from_bottom(t_data **stack, t_data *elem);
int			get_pos_from_top(t_data **stack, t_data *elem);
int			get_max_pos(t_data **stack, t_data *elem);
int			get_min_pos(t_data **stack, t_data *elem);
void		adjust_stack(t_data **stack, t_data *hold, int pos);
void		adjust_stackmax(t_data **stack, int pos);
void		adjust_stackmin(t_data **stack, int pos);
void		get_final_stack(t_data **stack_a, t_data **stack_b);

#endif
