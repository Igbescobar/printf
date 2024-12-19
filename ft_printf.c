
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		print_char((int)*str);
		i++;
		str++;
	}
	return (i);
}

int	print_digit(long n, int base)
{
	char	*symbols;

	symbols = "0123456789abcdf";
	if (n < 0)
	{
		write(1, '-', 1);
		return (print_char(print_digit(-n, base) + 1));
	}
	else if (n < base)
		return (print_char());
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string((long)va_arg(ap, const char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += print_digit(va_arg(ap, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int i;
}