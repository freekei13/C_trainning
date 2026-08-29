#include "philo.h"

void	printing_philo(t_philo *p_db, char *message)
{
	pthread_mutex_lock(&p_db->db->db_mutex.p_print);
	printf(message, ms_now(p_db->db->start_time), p_db->id);
	pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
}

int	taking_fork_left(t_philo *p_db)
{
	pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
	if (stop_simulation(p_db) == -1)
		return (pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]), -1);
	printing_philo(p_db, MSG_FORK);
	return (0);
}

int	taking_fork_right(t_philo *p_db)
{
	pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
	if (stop_simulation(p_db) == -1)
		return (pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]), -1);
	printing_philo(p_db, MSG_FORK);
	return (0);
}

int	taking_forks(t_philo *p_db)
{
	if (p_db->id % 2 != 0)
	{
		usleep(p_db->db->time_to_eat / 10);
		if (taking_fork_left(p_db) != 0)
			return (-1);
		if (p_db->db->philo_nb == 1)
		{
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
			return (-1);
		}
		if (taking_fork_right(p_db) != 0)
			return (-1);
	}
	else
	{
		if (taking_fork_right(p_db) != 0)
			return (-1);
		if (taking_fork_left(p_db) != 0)
			return (-1);
	}
	return (0);
}

void	eating_philo(t_philo *p_db)
{
	pthread_mutex_lock(&p_db->philo_mutex.last_meal);
	gettimeofday(&p_db->last_meal, NULL);
	pthread_mutex_unlock(&p_db->philo_mutex.last_meal);
	printing_philo(p_db, MSG_EAT);
	usleep(p_db->db->time_to_eat * 1000);
	pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
	pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
	if (p_db->db->must_eat != -1)
	{
		pthread_mutex_lock(&p_db->philo_mutex.meal_eaten);
		p_db->meal_eaten++;
		pthread_mutex_unlock(&p_db->philo_mutex.meal_eaten);
	}
}
