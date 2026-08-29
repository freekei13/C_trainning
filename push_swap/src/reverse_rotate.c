#include "push_swap.h"

void	re_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

void	re_rotate_b(t_list **stack_b)
{
	t_list	*second_last;
	t_list	*last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	second_last = *stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
}

t_list	*find_second_last_lst(t_list *stack)
{
	t_list	*second_last;

	second_last = stack;
	while (second_last->next->next)
		second_last = second_last->next;
	return (second_last);
}

void	rra_rrb(t_list **stack_a, t_list **stack_b)
{
	t_list	*second_last_a;
	t_list	*last_a;
	t_list	*second_last_b;
	t_list	*last_b;

	if (ft_lstsize(*stack_a) > 1)
	{
		second_last_a = find_second_last_lst(*stack_a);
		last_a = second_last_a->next;
		second_last_a->next = NULL;
		last_a->next = *stack_a;
		*stack_a = last_a;
	}
	if (ft_lstsize(*stack_b) > 1)
	{
		second_last_b = find_second_last_lst(*stack_b);
		last_b = second_last_b->next;
		second_last_b->next = NULL;
		last_b->next = *stack_b;
		*stack_b = last_b;
	}
	ft_printf("rrr\n");
}
