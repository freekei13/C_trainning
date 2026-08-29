#include "pipex_bonus.h"

int	open_file(char *path, int in_out)
{
	int	fd;

	if (in_out == 0)
	{
		if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
			perror(path);
		fd = open(path, O_RDONLY);
		if (fd == -1)
			fd = open("/dev/null", O_RDONLY);
		return (fd);
	}
	else if (in_out == 1)
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(path);
			exit(-1);
		}
		return (fd);
	}
	return (-1);
}

char	**paths_parse(char **env)
{
	int		i;
	char	*path_s;
	char	*tmp;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) != NULL)
		{
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
				&& env[i][3] == 'H' && env[i][4] == '=')
				break ;
		}
		i++;
	}
	if (!env[i])
		return (NULL);
	tmp = ft_strchr(env[i], '=') + 1;
	path_s = ft_substr(tmp, 0, ft_strlen(tmp));
	paths = ft_split(path_s, ':');
	free(path_s);
	return (paths);
}

char	*full_path_parse(char *path, char *cmd)
{
	int		size;
	char	*full_path;
	char	*tmp;

	size = ft_strlen(path);
	if (path[size - 1] == '/')
	{
		full_path = ft_strjoin(path, cmd);
		return (full_path);
	}
	tmp = ft_strjoin(path, "/");
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

char	*find_full_path(char *cmd, char **env)
{
	int		i;
	char	*full_path;
	char	**paths;

	i = 0;
	if (!cmd)
		return (NULL);
	paths = paths_parse(env);
	while (paths[i])
	{
		full_path = full_path_parse(paths[i], cmd);
		if (access(full_path, F_OK) == 0)
			return (free_all(paths), full_path);
		free(full_path);
		i++;
	}
	free_all(paths);
	return (NULL);
}

void	print_error_exit(char *str)
{
	perror(str);
	exit(0);
}
