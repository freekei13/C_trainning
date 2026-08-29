#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define MAX_PHILOS	250
# define MSG_ERR_PHILO "Error: Number of philophers must be 1 to %d\n"
# define MSG_ERR_DIGIT	"Error: Arguments must be in digit !\
between 0 and 2147483647.\n"
# define MSG_ERR_NARG	"Error: number of arguments must be 4 or 5.\n\
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define MSG_ERR_THREAD	"Error: Could not create thread.\n"
# define MSG_ERR_MALLOC	"Error: Could not allocate memory.\n"
# define MSG_ERR_MUTEX	"Error: Could not create mutex.\n"

# define MSG_FORK "%ld %d has taken a fork\n"
# define MSG_EAT "%ld %d is eating\n"
# define MSG_SLEEP "%ld %d is sleeping\n"
# define MSG_THINK "%ld %d is thinking\n"
# define MSG_DIE "%ld %d died\n"

typedef struct s_mutex
{
	pthread_mutex_t	p_die;
	pthread_mutex_t	p_print;
}					t_mutex;

typedef struct s_p_mutex
{
	pthread_mutex_t	last_meal;
	pthread_mutex_t	meal_eaten;
	pthread_mutex_t	done_eat;
}					t_p_mutex;

typedef struct s_data
{
	int				philo_nb;
	pthread_t		*threads;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	struct timeval	start_time;
	int				someone_die;
	int				all_full;
	pthread_mutex_t	*forks;
	t_mutex			db_mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				fork_right;
	int				fork_left;
	struct timeval	last_meal;
	int				meal_eaten;
	int				done_eat;
	long			time_to_think;
	t_p_mutex		philo_mutex;
	t_data			*db;
}					t_philo;

int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
long	ms_now(struct timeval time_start);
void	mutex_destroy(pthread_mutex_t *mutex, int nb_mutex);

int		args_check(int ac, char **av);

int		db_parsing(t_data *db, char **av);
int		p_db_parsing(t_data *db, t_philo *p_db, int index);

int		simulation_start(t_data *db, t_philo *p_db);

void	printing_philo(t_philo *p_db, char *message);
int		taking_forks(t_philo *p_db);
void	eating_philo(t_philo *p_db);
int		stop_simulation(t_philo *p_db);

void	thinking_philo(t_philo *p_db);

int		someone_die_check(t_philo *p_db);
int		someone_full_check(t_philo *p_db);
int		reaper_monitor(t_philo *p_db);

void	mutex_destroy(pthread_mutex_t *mutex, int nb_mutex);
void	threads_join(pthread_t *threads, int nb_threads);
void	db_cleaner(t_data *db);
void	p_db_cleaner(t_philo *p_db, int nb);
#endif