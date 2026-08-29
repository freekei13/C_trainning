#include "so_long.h"

void	*set_img(void *mlx, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return (img);
}

int	set_pos_x(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	set_pos_y(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

t_data	set_data(char **map)
{
	t_data	data;

	data.mlx = mlx_init();
	data.c_img = set_img(data.mlx, "./sprite/collectible.xpm");
	data.e_img = set_img(data.mlx, "./sprite/exit.xpm");
	data.f_img = set_img(data.mlx, "./sprite/floor.xpm");
	data.w_img = set_img(data.mlx, "./sprite/wall.xpm");
	data.p_img.p_down = set_img(data.mlx, "./sprite/character_down.xpm");
	data.p_img.p_up = set_img(data.mlx, "./sprite/character_up.xpm");
	data.p_img.p_right = set_img(data.mlx, "./sprite/character_right.xpm");
	data.p_img.p_left = set_img(data.mlx, "./sprite/character_left.xpm");
	data.map = map;
	data.size.height = ft_tablen(map);
	data.size.width = ft_strlen(map[0]) - 1;
	data.p_pos.x = set_pos_x(map);
	data.p_pos.y = set_pos_y(map);
	data.collec_count = element_to_count(map, 'C');
	data.move_count = 0;
	data.window = mlx_new_window(data.mlx, data.size.width * TILE,
			data.size.height * TILE, "so_long");
	return (data);
}
