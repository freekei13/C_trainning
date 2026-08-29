#include "push_swap.h"

void	rotate_a(t_list	**stack_a)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	last = ft_lstlast(*stack_a);
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	last = ft_lstlast(*stack_b);
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	ra_rb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*last_a;
	t_list	*first_b;
	t_list	*last_b;

	if (ft_lstsize(*stack_a) > 1)
	{
		first_a = *stack_a;
		*stack_a = (*stack_a)->next;
		last_a = ft_lstlast(*stack_a);
		last_a->next = first_a;
		first_a->next = NULL;
	}
	if (ft_lstsize(*stack_b) > 1)
	{
		first_b = *stack_b;
		*stack_b = (*stack_b)->next;
		last_b = ft_lstlast(*stack_b);
		last_b->next = first_b;
		first_b->next = NULL;
	}
	ft_printf("rr\n");
}
