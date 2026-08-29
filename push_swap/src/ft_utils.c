#include "push_swap.h"

int	find_min_index(t_list *stack_a)
{
	int		min;
	t_list	*tmp;

	tmp = stack_a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max_index(t_list *stack_a)
{
	int		max;
	t_list	*tmp;

	tmp = stack_a;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_index_pos(t_list *stack_a, int index)
{
	int		pos;
	t_list	*tmp;

	tmp = stack_a;
	pos = 0;
	while (tmp->index != index)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_max(int first, int second)
{
	if (first > second)
		return (first);
	else
		return (second);
}
