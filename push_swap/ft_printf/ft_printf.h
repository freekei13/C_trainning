#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_print_char(int arg);
int		ft_print_str(char *arg);
int		ft_print_nbr(long nb);
int		ft_print_unbr(unsigned long nb);
int		ft_print_hex(unsigned long long arg, char c);
int		ft_print_ptr(void *arg);

#endif