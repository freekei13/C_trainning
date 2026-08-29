#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE
#  define TILE 16
# endif
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>

typedef struct s_map
{
	int	width;
	int	height;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_player
{
	void	*p_down;
	void	*p_up;
	void	*p_right;
	void	*p_left;
}			t_player;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**map;
	t_map		size;
	t_pos		p_pos;
	void		*c_img;
	void		*e_img;
	t_player	p_img;
	void		*f_img;
	void		*w_img;
	int			move_count;
	int			collec_count;
}				t_data;

void	free_all(char **strs);
void	free_all_img(t_data *data);
int		ft_tablen(char **strs);
int		exit_game(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		element_to_count(char **map, char element);
char	**new_bigger_tab(int old_size, char **old_tab, char *line);
char	**map_parse(int fd);
char	**map_check(char *file_path);
int		isacces(char **map);

t_data	set_data(char **map);
void	*set_img(void *mlx, char *path);
int		set_pos_y(char **map);
int		set_pos_x(char **map);

void	map_render_key(t_data *data, int key);
void	map_render(t_data *data);
void	re_render_key(t_data *data, int key);

int		key_actions(int key, t_data *data);
#endif