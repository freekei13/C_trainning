#include "philo.h"

int	mutex_inits(pthread_mutex_t *mutex, int nb_mutex)
{
	int	i;

	i = 0;
	while (i < nb_mutex)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
		{
			mutex_destroy(mutex, i);
			ft_putstr_fd(MSG_ERR_MUTEX, 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	db_mutex_inits(t_mutex *db_mutex)
{
	if (pthread_mutex_init(&db_mutex->p_die, NULL) != 0)
	{
		ft_putstr_fd(MSG_ERR_MUTEX, 2);
		return (-1);
	}
	if (pthread_mutex_init(&db_mutex->p_print, NULL) != 0)
	{
		ft_putstr_fd(MSG_ERR_MUTEX, 2);
		pthread_mutex_destroy(&db_mutex->p_die);
		return (-1);
	}
	return (0);
}

int	db_parsing(t_data *db, char **av)
{
	db->philo_nb = (int)ft_atol(av[1]);
	db->time_to_die = ft_atol(av[2]);
	db->time_to_eat = ft_atol(av[3]);
	db->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		db->must_eat = (int)ft_atol(av[5]);
	else
		db->must_eat = -1;
	db->someone_die = 0;
	db->all_full = 0;
	db->threads = malloc(sizeof(pthread_t) * (db->philo_nb + 1));
	if (!db->threads)
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), -1);
	db->forks = malloc(sizeof(pthread_mutex_t) * db->philo_nb);
	if (!db->forks)
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), free(db->threads), -1);
	if (mutex_inits(db->forks, db->philo_nb) != 0)
		return (free(db->threads), free(db->forks), -1);
	if (db_mutex_inits(&db->db_mutex) != 0)
	{
		mutex_destroy(db->forks, db->philo_nb);
		return (free(db->threads), free(db->forks), -1);
	}
	return (0);
}

int	philo_mutex_init(t_p_mutex *philo_mutex)
{
	if (pthread_mutex_init(&philo_mutex->last_meal, NULL) != 0)
	{
		ft_putstr_fd(MSG_ERR_MUTEX, 2);
		return (-1);
	}
	if (pthread_mutex_init(&philo_mutex->meal_eaten, NULL) != 0)
	{
		ft_putstr_fd(MSG_ERR_MUTEX, 2);
		pthread_mutex_destroy(&philo_mutex->last_meal);
		return (-1);
	}
	if (pthread_mutex_init(&philo_mutex->done_eat, NULL) != 0)
	{
		ft_putstr_fd(MSG_ERR_MUTEX, 2);
		pthread_mutex_destroy(&philo_mutex->last_meal);
		pthread_mutex_destroy(&philo_mutex->meal_eaten);
		return (-1);
	}
	return (0);
}

int	p_db_parsing(t_data *db, t_philo *p_db, int index)
{
	p_db->id = index + 1;
	p_db->fork_right = (index + 1) % db->philo_nb;
	p_db->fork_left = index;
	gettimeofday(&p_db->last_meal, NULL);
	p_db->meal_eaten = 0;
	p_db->done_eat = 0;
	p_db->time_to_think = 0;
	p_db->db = db;
	if (philo_mutex_init(&p_db->philo_mutex) != 0)
		return (-1);
	return (0);
}
