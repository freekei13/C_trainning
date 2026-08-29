#include "so_long.h"

void	player_render_key(t_data *data, int key)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && key == 's')
				mlx_put_image_to_window(data->mlx, data->window,
					data->p_img.p_down, j * TILE, i * TILE);
			if (data->map[i][j] == 'P' && key == 'w')
				mlx_put_image_to_window(data->mlx, data->window,
					data->p_img.p_up, j * TILE, i * TILE);
			if (data->map[i][j] == 'P' && key == 'a')
				mlx_put_image_to_window(data->mlx, data->window,
					data->p_img.p_left, j * TILE, i * TILE);
			if (data->map[i][j] == 'P' && key == 'd')
				mlx_put_image_to_window(data->mlx, data->window,
					data->p_img.p_right, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}

void	element_render(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->w_img, j * TILE, i * TILE);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->window,
			data->f_img, j * TILE, i * TILE);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->e_img, j * TILE, i * TILE);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->c_img, j * TILE, i * TILE);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->window,
			data->p_img.p_down, j * TILE, i * TILE);
}

void	map_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			element_render(data, i, j);
			j++;
		}
		i++;
	}
}

void	element_render_key(t_data *data, int key, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->w_img, j * TILE, i * TILE);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->window,
			data->f_img, j * TILE, i * TILE);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->e_img, j * TILE, i * TILE);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->c_img, j * TILE, i * TILE);
	if (data->map[i][j] == 'P')
		player_render_key(data, key);
}

void	map_render_key(t_data *data, int key)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			element_render_key(data, key, i, j);
			j++;
		}
		i++;
	}
}
