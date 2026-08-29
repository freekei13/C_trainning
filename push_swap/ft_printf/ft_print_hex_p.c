#include "ft_printf.h"

int	ft_hexlen(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_print_hex(unsigned long long arg, char c)
{
	char	*base_hex;
	char	hex[16];
	int		i;
	int		len;

	if (arg == 0)
		return (ft_print_char('0'));
	if (c == 'X')
		base_hex = "0123456789ABCDEF";
	else
		base_hex = "0123456789abcdef";
	i = 0;
	len = ft_hexlen(arg);
	while (arg != 0)
	{
		hex[i] = base_hex[arg % 16];
		arg = arg / 16;
		i++;
	}
	while (hex[i - 1])
	{
		write(1, &hex[i - 1], 1);
		i--;
	}
	return (len);
}

int	ft_print_ptr(void *arg)
{
	unsigned long long	ptr;
	int					len;

	len = 0;
	ptr = (unsigned long long)arg;
	if (ptr == 0)
		return (ft_print_str("(nil)"));
	len += ft_print_str("0x");
	len += ft_print_hex(ptr, 'x');
	return (len);
}
