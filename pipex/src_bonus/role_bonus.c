#include "pipex_bonus.h"

void	exec_cmd(char *arg, char *cmd_path, char **cmd, char **env)
{
	if (!cmd_path)
	{
		if (cmd[0] == NULL)
			ft_putstr_fd("", 2);
		else
			ft_putstr_fd(cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_all(cmd);
		exit(127);
	}
	if (execve(cmd_path, cmd, env) == -1)
	{
		perror(arg);
		free_all(cmd);
		free(cmd_path);
		exit(126);
	}
}

void	n_child(char *av, char **env, t_data *data, int *pipefd)
{
	char	**cmd;
	char	*cmd_path;

	dup2(data->prev_fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(data->prev_fd);
	close(data->fd_out);
	cmd = ft_split(av, ' ');
	cmd_path = find_full_path(cmd[0], env);
	exec_cmd(av, cmd_path, cmd, env);
}

void	l_child(char *av, char **env, int fd, int prev_fd)
{
	char	**cmd;
	char	*cmd_path;

	dup2(fd, 1);
	dup2(prev_fd, 0);
	close(fd);
	close(prev_fd);
	cmd = ft_split(av, ' ');
	cmd_path = find_full_path(cmd[0], env);
	exec_cmd(av, cmd_path, cmd, env);
}

void	parent_role(t_data *data, int i, int *pipefd)
{
	if (i != data->n_cmd - 1)
	{
		close(data->prev_fd);
		close(pipefd[1]);
		data->prev_fd = pipefd[0];
	}
}

void	l_child_role(pid_t pid, t_data *data, char **av, char **env)
{
	pid = fork();
	if (pid == -1)
		print_error_exit("n_pid");
	if (pid == 0)
		l_child(av[data->start_cmd + data->n_cmd - 1],
			env, data->fd_out, data->prev_fd);
}
