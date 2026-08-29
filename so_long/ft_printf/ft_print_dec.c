#include "ft_printf.h"

int	ft_intlen(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_print_nbr(long nb)
{
	int	len;

	len = ft_intlen(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_print_nbr(nb);
	}
	else if (nb > 9)
	{
		ft_print_nbr(nb / 10);
		ft_print_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}

int	ft_print_unbr(unsigned long nb)
{
	int	len;

	len = ft_intlen(nb);
	if (nb > 9)
	{
		ft_print_nbr(nb / 10);
		ft_print_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
