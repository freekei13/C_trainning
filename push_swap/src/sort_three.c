#include "push_swap.h"

void	three_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	max_pos;

	min_pos = find_index_pos(*stack_a, find_min_index(*stack_a));
	max_pos = find_index_pos(*stack_a, find_max_index(*stack_a));
	if (min_pos == 0 && max_pos == 1)
	{
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_a(stack_a, stack_b);
	}
	if (min_pos == 1 && max_pos == 0)
		rotate_a(stack_a);
	if (min_pos == 1 && max_pos == 2)
		swap_a(stack_a);
	if (min_pos == 2 && max_pos == 0)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	if (min_pos == 2 && max_pos == 1)
		re_rotate_a(stack_a);
}
