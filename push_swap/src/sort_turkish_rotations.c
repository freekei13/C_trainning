#include "push_swap.h"

void	scena_rr(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;

	i = -1;
	if (pos_a > pos_b)
	{
		while (++i < pos_b)
			ra_rb(a, b);
		i = -1;
		while (++i < pos_a - pos_b)
			rotate_a(a);
	}
	else if (pos_a < pos_b)
	{
		while (++i < pos_a)
			ra_rb(a, b);
		i = -1;
		while (++i < pos_b - pos_a)
			rotate_b(b);
	}
	else
		while (++i < pos_a)
			ra_rb(a, b);
}

void	scena_rrr(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;

	i = -1;
	if (ft_lstsize(*a) - pos_a > ft_lstsize(*b) - pos_b)
	{
		while (++i < ft_lstsize(*b) - pos_b)
			rra_rrb(a, b);
		i = -1;
		while (++i < (ft_lstsize(*a) - pos_a) - (ft_lstsize(*b) - pos_b))
			re_rotate_a(a);
	}
	else if (ft_lstsize(*a) - pos_a < ft_lstsize(*b) - pos_b)
	{
		while (++i < ft_lstsize(*a) - pos_a)
			rra_rrb(a, b);
		i = -1;
		while (++i < (ft_lstsize(*b) - pos_b) - (ft_lstsize(*a) - pos_a))
			re_rotate_b(b);
	}
	else
		while (++i < ft_lstsize(*a) - pos_a)
			rra_rrb(a, b);
}

void	scena_ra_rrb(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;
	int	size_b;

	i = -1;
	size_b = ft_lstsize(*b);
	while (++i < pos_a)
		rotate_a(a);
	i = -1;
	while (++i < size_b - pos_b)
		re_rotate_b(b);
}

void	scena_rra_rb(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;
	int	size_a;

	i = -1;
	size_a = ft_lstsize(*a);
	while (++i < pos_b)
		rotate_b(b);
	i = -1;
	while (++i < size_a - pos_a)
		re_rotate_a(a);
}

void	scena_action(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	*costs;
	int	scena;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	costs = cost_diff_scena(pos_a, pos_b, size_a, size_b);
	if (!costs)
		return ;
	scena = cheapest_scena(costs);
	free(costs);
	if (scena == 0)
		scena_rr(pos_a, pos_b, a, b);
	else if (scena == 1)
		scena_rrr(pos_a, pos_b, a, b);
	else if (scena == 2)
		scena_ra_rrb(pos_a, pos_b, a, b);
	else if (scena == 3)
		scena_rra_rb(pos_a, pos_b, a, b);
	push_a(a, b);
}
