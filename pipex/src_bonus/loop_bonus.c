#include "pipex_bonus.h"

void	pipex_loop(char **av, char **env, t_data *data)
{
	pid_t	n_pid;
	int		pipefd[2];
	int		i;

	data->prev_fd = data->fd_in;
	i = 0;
	while (i < data->n_cmd)
	{
		if (i == data->n_cmd - 1)
			l_child_role(n_pid, data, av, env);
		else
		{
			if (pipe(pipefd) == -1)
				print_error_exit("pipe");
			n_pid = fork();
			if (n_pid == -1)
				print_error_exit("n_pid");
			if (n_pid == 0)
				n_child(av[data->start_cmd + i], env, data, pipefd);
		}
		parent_role(data, i, pipefd);
		i++;
	}
}

void	here_doc_loop(char **av, int *pipefd)
{
	char	*input;

	close(pipefd[0]);
	while (1)
	{
		input = get_next_line(0);
		if (ft_strncmp(av[2], input, ft_strlen(av[2])) == 0
			&& ft_strlen(av[2]) == ft_strlen(input) - 1)
		{
			free(input);
			close(pipefd[1]);
			exit(0);
		}
		ft_putstr_fd(input, pipefd[1]);
		free(input);
	}
}
//get_next_line(-1); entre ligne 54 et 55 pour couvrir le leak;