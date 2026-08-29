#include "pipex.h"

void	exec_cmd(char *arg, char *cmd_path, char **cmd, char **env)
{
	if (!cmd_path)
	{
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

void	f_child(char **av, char **env, int *pipefd)
{
	int		fd;
	char	**cmd;
	char	*cmd_path;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd = ft_split(av[2], ' ');
	cmd_path = find_full_path(cmd[0], env);
	exec_cmd(av[2], cmd_path, cmd, env);
}

void	s_child(char **av, char **env, int *pipefd)
{
	int		fd;
	char	**cmd;
	char	*cmd_path;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd = ft_split(av[3], ' ');
	cmd_path = find_full_path(cmd[0], env);
	exec_cmd(av[3], cmd_path, cmd, env);
}

void	pipex(int ac, char **av, char **env)
{
	pid_t	first_child;
	pid_t	second_child;
	int		pipefd[2];
	int		status_f;
	int		status_s;

	if (ac != 5)
	{
		ft_putstr_fd("pipex: file1 cmd1 cmd2 file2", 2);
		return ;
	}
	pipe(pipefd);
	first_child = fork();
	if (first_child == 0)
		f_child(av, env, pipefd);
	second_child = fork();
	if (second_child == 0)
		s_child(av, env, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(first_child, &status_f, 0);
	waitpid(second_child, &status_s, 0);
}

int	main(int argc, char **argv, char **env)
{
	pipex(argc, argv, env);
	return (0);
}
