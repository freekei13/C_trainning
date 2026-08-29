#include "push_swap.h"

int	*lis_assem(int *a, int *prev, int max_len, int end)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * (max_len + 1));
	if (!lis)
		return (NULL);
	i = max_len - 1;
	j = end;
	while (j != -1)
	{
		lis[i] = a[j];
		i--;
		j = prev[j];
	}
	lis[max_len] = -1;
	return (lis);
}

void	set_lis_maxlen_end(int *max_len, int *end, int size, int *len)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (len[i] > *max_len)
		{
			*max_len = len[i];
			*end = i;
		}
		i++;
	}
}

void	set_len_prev(int *a, int *len, int *prev, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (a[j] < a[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*build_lis(int *a, int *len, int *prev, int size)
{
	int	max_len;
	int	end;
	int	*lis;

	max_len = 0;
	end = 0;
	set_lis_maxlen_end(&max_len, &end, size, len);
	lis = lis_assem(a, prev, max_len, end);
	if (!lis)
		return (free(len), free(prev), free(a), NULL);
	return (free(len), free(prev), free(a), lis);
}

int	*set_lis(t_list *stack_a)
{
	int	*a;
	int	*len;
	int	*prev;
	int	size;
	int	*lis;

	size = ft_lstsize(stack_a);
	a = parse_index(stack_a);
	len = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!len || !prev || !a)
		return (free(len), free(prev), free(a), NULL);
	set_len_prev(a, len, prev, size);
	lis = build_lis(a, len, prev, size);
	if (!lis)
		return (NULL);
	return (lis);
}
