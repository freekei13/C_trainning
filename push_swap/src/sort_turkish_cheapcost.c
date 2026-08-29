#include "push_swap.h"

int	*cost_diff_scena(int pos_a, int pos_b, int size_a, int size_b)
{
	int	*costs;

	costs = malloc(sizeof(int) * 4);
	if (!costs)
		return (NULL);
	costs[0] = find_max(pos_a, pos_b);
	costs[1] = find_max(size_a - pos_a, size_b - pos_b);
	costs[2] = pos_a + (size_b - pos_b);
	costs[3] = (size_a - pos_a) + pos_b;
	return (costs);
}

int	cheapest_cost(int *costs)
{
	int	cheapest;
	int	i;

	i = 0;
	cheapest = costs[0];
	while (i < 4)
	{
		if (cheapest > costs[i])
			cheapest = costs[i];
		i++;
	}
	return (cheapest);
}

int	cheapest_scena(int *costs)
{
	int	cheapest;
	int	i;
	int	scena;

	scena = 0;
	i = 0;
	cheapest = costs[0];
	while (i < 4)
	{
		if (cheapest > costs[i])
		{
			cheapest = costs[i];
			scena = i;
		}
		i++;
	}
	return (scena);
}
