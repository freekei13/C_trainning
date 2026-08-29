#include "philo.h"

int	main(int ac, char **av)
{
	t_data		db;
	t_philo		*philo_db;

	if (args_check(ac, av) != 0)
		return (-1);
	if (db_parsing(&db, av) != 0)
		return (-1);
	philo_db = malloc(sizeof(t_philo) * db.philo_nb);
	if (!philo_db)
	{
		db_cleaner(&db);
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), -1);
	}
	if (simulation_start(&db, philo_db) != 0)
		return (free(philo_db), -1);
	p_db_cleaner(philo_db, db.philo_nb);
	db_cleaner(&db);
	free(philo_db);
	return (0);
}
