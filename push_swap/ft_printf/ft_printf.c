#include "ft_printf.h"

int	ft_arguments(va_list args, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_unbr(va_arg(args, unsigned int));
	else if (type == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), 'x');
	else if (type == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), 'X');
	else if (type == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_total;

	i = 0;
	len_total = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len_total += ft_arguments(args, format[i + 1]);
			i++;
		}
		else
			len_total += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len_total);
}
