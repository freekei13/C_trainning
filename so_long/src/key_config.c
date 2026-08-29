#include "so_long.h"
#include "/usr/include/X11/keysym.h"

void	w_key_action(t_data *data)
{
	if (data->map[data->p_pos.y - 1][data->p_pos.x] == '1')
		return ;
	else if (data->map[data->p_pos.y - 1][data->p_pos.x] == 'C')
	{
		data->collec_count -= 1;
		if (data->collec_count == 0)
			ft_printf("You have stolen all pokeball, Go to the exit now !!\n");
	}
	else if (data->map[data->p_pos.y - 1][data->p_pos.x] == 'E')
	{
		if (data->collec_count == 0)
		{
			ft_printf("Move: %d\n", data->move_count + 1);
			ft_printf("Your job is done here! Good job !\n");
			exit_game(data);
		}
		ft_printf("You have to steal all pokeball before leaving !\n");
		return ;
	}
	data->map[data->p_pos.y][data->p_pos.x] = '0';
	data->map[data->p_pos.y - 1][data->p_pos.x] = 'P';
	data->p_pos.y -= 1;
	data->move_count += 1;
	ft_printf("Move: %d\n", data->move_count);
}

void	s_key_action(t_data *data)
{
	if (data->map[data->p_pos.y + 1][data->p_pos.x] == '1')
		return ;
	else if (data->map[data->p_pos.y + 1][data->p_pos.x] == 'C')
	{
		data->collec_count -= 1;
		if (data->collec_count == 0)
			ft_printf("You have stolen all pokeball, Go to the exit now !!\n");
	}
	else if (data->map[data->p_pos.y + 1][data->p_pos.x] == 'E')
	{
		if (data->collec_count == 0)
		{
			ft_printf("Move: %d\n", data->move_count + 1);
			ft_printf("Your job is done here! Good job !\n");
			exit_game(data);
		}
		ft_printf("You have to steal all pokeball before leaving !\n");
		return ;
	}
	data->map[data->p_pos.y][data->p_pos.x] = '0';
	data->map[data->p_pos.y + 1][data->p_pos.x] = 'P';
	data->p_pos.y += 1;
	data->move_count += 1;
	ft_printf("Move: %d\n", data->move_count);
}

void	a_key_action(t_data *data)
{
	if (data->map[data->p_pos.y][data->p_pos.x - 1] == '1')
		return ;
	else if (data->map[data->p_pos.y][data->p_pos.x - 1] == 'C')
	{
		data->collec_count -= 1;
		if (data->collec_count == 0)
			ft_printf("You have stolen all pokeball, Go to the exit now !!\n");
	}
	else if (data->map[data->p_pos.y][data->p_pos.x - 1] == 'E')
	{
		if (data->collec_count == 0)
		{
			ft_printf("Move: %d\n", data->move_count + 1);
			ft_printf("Your job is done here! Good job !\n");
			exit_game(data);
		}
		ft_printf("You have to steal all pokeball before leaving !\n");
		return ;
	}
	data->map[data->p_pos.y][data->p_pos.x] = '0';
	data->map[data->p_pos.y][data->p_pos.x - 1] = 'P';
	data->p_pos.x -= 1;
	data->move_count += 1;
	ft_printf("Move: %d\n", data->move_count);
}

void	d_key_action(t_data *data)
{
	if (data->map[data->p_pos.y][data->p_pos.x + 1] == '1')
		return ;
	else if (data->map[data->p_pos.y][data->p_pos.x + 1] == 'C')
	{
		data->collec_count -= 1;
		if (data->collec_count == 0)
			ft_printf("You have stolen all pokeball, Go to the exit now !!\n");
	}
	else if (data->map[data->p_pos.y][data->p_pos.x + 1] == 'E')
	{
		if (data->collec_count == 0)
		{
			ft_printf("Move: %d\n", data->move_count + 1);
			ft_printf("Your job is done here! Good job !\n");
			exit_game(data);
		}
		ft_printf("You have to steal all pokeball before leaving !\n");
		return ;
	}
	data->map[data->p_pos.y][data->p_pos.x] = '0';
	data->map[data->p_pos.y][data->p_pos.x + 1] = 'P';
	data->p_pos.x += 1;
	data->move_count += 1;
	ft_printf("Move: %d\n", data->move_count);
}

int	key_actions(int key, t_data *data)
{
	if (key == XK_Escape)
		exit_game(data);
	if (key == 'w')
		w_key_action(data);
	if (key == 's')
		s_key_action(data);
	if (key == 'a')
		a_key_action(data);
	if (key == 'd')
		d_key_action(data);
	if (key == 'd' || key == 'a' || key == 's' || key == 'w')
		map_render_key(data, key);
	return (0);
}
