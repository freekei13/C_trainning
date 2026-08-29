#include "so_long.h"

void	flood_fill(char **map, int y, int x)
{
	int	height;
	int	width;

	height = ft_tablen(map);
	width = ft_strlen(map[0]) - 1;
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

char	**dup_map(char **map)
{
	char	**tmp;
	int		height;
	int		i;

	height = ft_tablen(map);
	tmp = malloc(sizeof(char *) * height);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < height - 1)
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int	isacces(char **map)
{
	char	**tmp;
	int		y;
	int		x;

	tmp = dup_map(map);
	y = set_pos_y(tmp);
	x = set_pos_x(tmp);
	flood_fill(tmp, y, x);
	if (element_to_count(tmp, 'E') > 0 || element_to_count(tmp, 'C') > 0)
		return (free_all(tmp), 0);
	free_all(tmp);
	return (ft_printf("Access to Collectible and Exit\n"), 1);
}
