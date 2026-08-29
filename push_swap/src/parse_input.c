#include "push_swap.h"

t_list	*parse_inputs(char **args)
{
	t_list	*stack_a;
	t_list	*node;
	int		nb;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		node = ft_lstnew(nb);
		if (!node)
			return (NULL);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

int	*parse_list(t_list *args)
{
	t_list	*stack;
	int		*tmp;
	int		i;

	tmp = malloc(ft_lstsize(args) * sizeof(int));
	if (!tmp)
		return (NULL);
	stack = args;
	i = 0;
	while (stack)
	{
		tmp[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return (tmp);
}

int	*parse_index(t_list *args)
{
	t_list	*stack;
	int		*tmp;
	int		i;

	tmp = malloc(ft_lstsize(args) * sizeof(int));
	if (!tmp)
		return (NULL);
	stack = args;
	i = 0;
	while (stack)
	{
		tmp[i] = stack->index;
		i++;
		stack = stack->next;
	}
	return (tmp);
}

void	buble_sort(int *args, int size)
{
	int	nb_tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (args[j] > args[j + 1])
			{
				nb_tmp = args[j];
				args[j] = args[j + 1];
				args[j + 1] = nb_tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_assign(t_list *args)
{
	int		*tmp;
	int		i;
	t_list	*head;
	int		size;

	head = args;
	i = ft_lstsize(args);
	tmp = parse_list(args);
	buble_sort(tmp, i);
	i = 0;
	size = ft_lstsize(head);
	while (i < size)
	{
		args = head;
		while (args)
		{
			if (args->content == tmp[i])
				args->index = i;
			args = args->next;
		}
		i++;
	}
	free(tmp);
}
