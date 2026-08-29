#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h> 
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

typedef struct s_data
{
	int	fd_in;
	int	fd_out;
	int	prev_fd;
	int	n_cmd;
	int	start_cmd;
	int	status;
}		t_data;

char	*find_full_path(char *cmd, char **env);
int		open_file(char *path, int in_out);
int		ft_tablen(char **strs);
void	print_error_exit(char *str);

void	pipex_loop(char **av, char **env, t_data *data);
void	here_doc_loop(char **av, int *pipefd);

void	n_child(char *av, char **env, t_data *data, int *pipefd);
void	l_child(char *av, char **env, int fd, int prev_fd);
void	parent_role(t_data *data, int i, int *pipefd);
void	l_child_role(pid_t pid, t_data *data, char **av, char **env);

#endif