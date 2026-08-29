#include "pipex_bonus.h"

void	here_doc(char **av, int *fd_in)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("here_doc");
		exit(0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("here_doc");
		exit(0);
	}
	if (pid == 0)
		here_doc_loop(av, pipefd);
	close(pipefd[1]);
	*fd_in = pipefd[0];
	wait(NULL);
}

void	set_start(int ac, char **av, t_data *data)
{
	if (ac < 5)
	{
		ft_putstr_fd("file1 cmd1 cmd2 cmdn file2\n", 2);
		exit(0);
	}
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		if (ac < 6)
		{
			ft_putstr_fd("here_doc LIMITER cmd1 cmd2 cmdn file", 2);
			exit(0);
		}
		here_doc(av, &(*data).fd_in);
		data->n_cmd = ac - 4;
	}
	else
	{
		data->n_cmd = ac - 3;
		data->fd_in = open_file(av[1], 0);
	}
}

void	pipex(int ac, char **av, char **env)
{
	t_data	data;

	set_start(ac, av, &data);
	data.start_cmd = ac - data.n_cmd - 1;
	data.fd_out = open_file(av[ac - 1], 1);
	pipex_loop(av, env, &data);
	close(data.fd_out);
	if (data.fd_in != data.prev_fd)
		close(data.fd_in);
	close(data.prev_fd);
	while (data.n_cmd > 0)
	{
		wait(&data.status);
		data.n_cmd--;
	}
}

int	main(int argc, char **argv, char **env)
{
	pipex(argc, argv, env);
	return (0);
}
