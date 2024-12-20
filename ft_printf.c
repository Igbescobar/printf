/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:58:42 by igngonza          #+#    #+#             */
/*   Updated: 2024/12/20 12:10:13 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	number_chars_printed;

	number_chars_printed = 0;
	if (specifier == '%')
		number_chars_printed += ft_print_char('%');
	else if (specifier == 'c')
		number_chars_printed += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		number_chars_printed += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		number_chars_printed = ft_print_ptr(va_arg(ap, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		number_chars_printed += ft_print_nbr(va_arg(ap, int));
	else if (specifier == 'u')
		number_chars_printed += ft_print_nbr_base(va_arg(ap, unsigned int), 10);
	else if (specifier == 'x')
		number_chars_printed += ft_print_nbr_base(va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		number_chars_printed += ft_print_nbr_base(va_arg(ap, unsigned int), 16);
	else
		number_chars_printed += write(1, &specifier, 1);
	return (number_chars_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
