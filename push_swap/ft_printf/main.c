#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		nb;
	int		unb;
	char	c;

	str = "Hello";
	nb = 42;
	unb = 35;
	c = 75;
	ft_printf(" %x \n", 0);
	printf(" NULL %s %i %c %p %u %x %X %%\n", NULL, nb, c, &c, unb, nb, nb);
	printf(" %x \n", 0);
}
