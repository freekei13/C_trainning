#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_char(int arg)
{
	write(1, &arg, 1);
	return (1);
}

int	ft_print_str(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (arg[i])
	{
		ft_putchar(arg[i]);
		i++;
	}
	return (i);
}
