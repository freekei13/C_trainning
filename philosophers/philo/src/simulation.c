#include "philo.h"

void	*routine(void *philo_db)
{
	t_philo	*p_db;

	p_db = (t_philo *)philo_db;
	while (1)
	{
		if (stop_simulation(p_db) != 0)
			return (NULL);
		if (taking_forks(p_db) != 0)
			return (NULL);
		if (stop_simulation(p_db) != 0)
			return (NULL);
		eating_philo(p_db);
		if (stop_simulation(p_db) != 0)
			return (NULL);
		printing_philo(p_db, MSG_SLEEP);
		usleep(p_db->db->time_to_sleep * 1000);
		if (stop_simulation(p_db) != 0)
			return (NULL);
		thinking_philo(p_db);
	}
	return (NULL);
}

void	*reaper(void *philo_db)
{
	t_philo	*p_db;
	int		i;

	p_db = (t_philo *)philo_db;
	i = 0;
	while (1)
	{
		if (reaper_monitor(&p_db[i]) != 0)
			return (NULL);
		if (i == p_db[i].db->philo_nb - 1)
		{
			i = 0;
			usleep(1000);
		}
		else
			i++;
	}
	return (NULL);
}

void	simulation_cleaner(t_data *db, t_philo *p_db, int index, char *msg)
{
	p_db->db->someone_die = 1;
	threads_join(db->threads, index);
	p_db_cleaner(p_db, index);
	db_cleaner(db);
	if (msg)
		ft_putstr_fd(msg, 2);
}

void	simulation_join(t_data *db)
{
	int	i;

	i = 0;
	while (i < db->philo_nb + 1)
	{
		pthread_join(db->threads[i], NULL);
		i++;
	}
}

int	simulation_start(t_data *db, t_philo *p_db)
{
	int	i;

	gettimeofday(&db->start_time, NULL);
	i = 0;
	while (i < db->philo_nb + 1)
	{
		if (i == db->philo_nb)
		{
			if (pthread_create(&db->threads[i], NULL, reaper, p_db) != 0)
				return (simulation_cleaner(db, p_db, i, MSG_ERR_THREAD), -1);
		}
		else
		{
			if (p_db_parsing(db, &p_db[i], i) != 0)
				return (simulation_cleaner(db, p_db, i, NULL), -1);
			if (pthread_create(&db->threads[i], NULL, routine, &p_db[i]) != 0)
				return (simulation_cleaner(db, p_db, i, MSG_ERR_THREAD), -1);
		}
		i++;
	}
	simulation_join(db);
	return (0);
}
