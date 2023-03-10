#include "../includes/push_swap.h"
    
void	ra(t_data **stack_a)
{
	move_to_end(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data **stack_b)
{
	move_to_end(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_data **stack_a)
{
	move_to_front(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data **stack_b)
{
	move_to_front(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
