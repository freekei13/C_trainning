#include "push_swap.h"

void	push_b_keep_lis(int size, int *lis, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	exist;

	while (size > 0 && *stack_a)
	{
		i = 0;
		exist = 0;
		while (lis[i] != -1)
		{
			if ((*stack_a)->index == lis[i])
				exist++;
			i++;
		}
		if (exist != 0)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
		size--;
	}
}

void	rotations_push_a(t_list **stack_a, t_list **stack_b)
{
	int	pos_a;
	int	pos_b;

	while (*stack_b)
	{
		pos_b = set_best_pos_b(*stack_a, *stack_b);
		pos_a = set_pos_a_target(*stack_a, find_pos_b_index(pos_b, *stack_b));
		scena_action(pos_a, pos_b, stack_a, stack_b);
	}
	while ((*stack_a)->index != 0)
	{
		if (find_index_pos(*stack_a, 0) > ft_lstsize(*stack_a) / 2)
			re_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	int	*lis;
	int	size;

	lis = set_lis(*stack_a);
	if (!lis)
		return ;
	size = ft_lstsize(*stack_a);
	push_b_keep_lis(size, lis, stack_a, stack_b);
	rotations_push_a(stack_a, stack_b);
	free(lis);
}
