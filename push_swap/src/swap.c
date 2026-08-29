#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_printf("sb\n");
}

void	sa_sb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;
	t_list	*second_b;

	if (ft_lstsize(*stack_a) > 1)
	{
		first_a = *stack_a;
		second_a = (*stack_a)->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		*stack_a = second_a;
	}
	if (ft_lstsize(*stack_b) > 1)
	{
		first_b = *stack_b;
		second_b = (*stack_b)->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		*stack_b = second_b;
	}
	ft_printf("ss\n");
}
