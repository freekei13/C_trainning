#include "push_swap.h"

void	pre_sort_four(t_list **stack_a, t_list **stack_b, int min)
{
	if (min == 3)
		re_rotate_a(stack_a);
	else if (min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min == 1)
		swap_a(stack_a);
	push_b(stack_a, stack_b);
}

void	four_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if ((*stack_a)->index == 0 && (*stack_a)->next->index == 1
		&& (*stack_a)->next->next->index == 2
		&& (*stack_a)->next->next->next->index == 3)
		return ;
	min = find_index_pos(*stack_a, find_min_index(*stack_a));
	pre_sort_four(stack_a, stack_b, min);
	three_args_sort(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
