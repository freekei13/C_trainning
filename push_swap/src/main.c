#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("a %d index %d --- b %d index %d\n",
				a->content, a->index, b->content, b->index);
			a = a->next;
			b = b->next;
		}
		if (a && !b)
		{
			ft_printf("a %d index %d --- b\n", a->content, a->index);
			a = a->next;
		}
		if (!a && b)
		{
			ft_printf("a           --- b %d index %d\n", b->content, b->index);
			b = b->next;
		}
	}
}

int	error_check(char **inputs)
{
	if (!inputs)
		return (0);
	else if (digit_check(inputs)
		&& repeat_check(inputs)
		&& int_minmax_check(inputs))
		return (1);
	else
		return (ft_printf("Error\n"), 0);
}

int	issorted(t_list *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->index != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**arg;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	arg = input_check(argc, argv);
	if (!arg)
		return (0);
	if (!error_check(arg))
		return (free_all(arg), 0);
	a = parse_inputs(arg);
	free_all(arg);
	index_assign(a);
	if (issorted(a) == 1)
		return (free_lst(&a), free_lst(&b), 0);
	push_swap(&a, &b);
	free_lst(&a);
	free_lst(&b);
}
