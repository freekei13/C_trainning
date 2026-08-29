#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	if (sign < 0)
		res = res * sign;
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long	ms_now(struct timeval time_start)
{
	struct timeval	time_now;
	long			ms;
	long			time_now_ms;
	long			time_start_ms;

	gettimeofday(&time_now, NULL);
	time_start_ms = (time_start.tv_sec * 1000) + (time_start.tv_usec / 1000);
	time_now_ms = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	ms = time_now_ms - time_start_ms;
	return (ms);
}

int	stop_simulation(t_philo *p_db)
{
	pthread_mutex_lock(&p_db->db->db_mutex.p_die);
	if (p_db->db->someone_die > 0 || p_db->db->all_full >= p_db->db->philo_nb)
	{
		pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
		return (-1);
	}
	pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
	return (0);
}
