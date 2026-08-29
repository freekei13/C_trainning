#include "builtin.h"

void	pwd(char **env, t_exec *exc_data)
{
	int	fd;

	exc_data->data->exit_status = 0;
	if (exc_data->fd_out == -1)
		fd = 1;
	else
		fd = exc_data->fd_out;
	ft_putendl_fd(find_env(env, "PWD"), fd);
}
