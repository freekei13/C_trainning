#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Pls enter a map's path\n");
		return (0);
	}
	map = map_check(argv[1]);
	if (!map)
		return (0);
	data = set_data(map);
	map_render(&data);
	mlx_hook(data.window, 2, 1L << 0, (int (*)())(void *)key_actions, &data);
	mlx_hook(data.window, 17, 0, (int (*)())(void *)exit_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
