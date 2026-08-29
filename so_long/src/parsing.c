#include "so_long.h"

char	**new_bigger_tab(int old_size, char **old_tab, char *line)
{
	char	**new;
	int		j;

	new = malloc(sizeof(char *) * (2 + old_size));
	j = 0;
	while (old_tab[j] != NULL)
	{
		new[j] = old_tab[j];
		j++;
	}
	new[j] = line;
	new[j + 1] = NULL;
	return (new);
}

int	check_map_component(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**map_parse(int fd)
{
	char	*line;
	char	**map;
	char	**new;
	int		i;

	map = malloc(sizeof(char *) * 2);
	line = get_next_line(fd);
	map[0] = line;
	map[1] = NULL;
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = new_bigger_tab(i, map, line);
		free(map);
		map = new;
		i++;
	}
	if (check_map_component(map) == 0)
		return (free_all(map), NULL);
	return (map);
}
