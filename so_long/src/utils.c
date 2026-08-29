#include "so_long.h"

void	free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_tablen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	free_all_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->p_img.p_down);
	mlx_destroy_image(data->mlx, data->p_img.p_up);
	mlx_destroy_image(data->mlx, data->p_img.p_right);
	mlx_destroy_image(data->mlx, data->p_img.p_left);
	mlx_destroy_image(data->mlx, data->c_img);
	mlx_destroy_image(data->mlx, data->e_img);
	mlx_destroy_image(data->mlx, data->f_img);
	mlx_destroy_image(data->mlx, data->w_img);
}

int	exit_game(t_data *data)
{
	free_all_img(data);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data->map);
	exit(0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i != n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
