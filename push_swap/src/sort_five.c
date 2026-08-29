#include "push_swap.h"

void	pre_sort_five(t_list	**stack_a, t_list **stack_b, int min)
{
	if (min == 4)
		re_rotate_a(stack_a);
	else if (min == 3)
	{
		re_rotate_a(stack_a);
		re_rotate_a(stack_a);
	}
	else if (min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min == 1)
		swap_a(stack_a);
	push_b(stack_a, stack_b);
}

void	five_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	second_min;

	if ((*stack_a)->index == 0 && (*stack_a)->next->index == 1
		&& (*stack_a)->next->next->index == 2
		&& (*stack_a)->next->next->next->index == 3
		&& (*stack_a)->next->next->next->next->index == 4)
		return ;
	min = find_index_pos(*stack_a, find_min_index(*stack_a));
	pre_sort_five(stack_a, stack_b, min);
	second_min = find_index_pos(*stack_a, find_min_index(*stack_a));
	pre_sort_four(stack_a, stack_b, second_min);
	three_args_sort(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);

}
