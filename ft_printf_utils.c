/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:56:49 by igngonza          #+#    #+#             */
/*   Updated: 2024/12/20 12:08:45 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	number_chars_printed;

	number_chars_printed = 0;
	while (*str)
	{
		ft_print_char((int)*str);
		number_chars_printed++;
		str++;
	}
	return (number_chars_printed);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	number_chars_printed;

	if (!ptr)
	{
		ft_print_str("(nil)");
		return (5);
	}
	number_chars_printed = 0;
	number_chars_printed += ft_print_str("0x");
	number_chars_printed += ft_print_nbr_base(ptr, 16);
	return (number_chars_printed);
}

int	ft_print_nbr(int n)
{
	unsigned int	aux_int;
	int				number_chars_printed;

	aux_int = 0;
	number_chars_printed = 0;
	if (n < 0)
	{
		ft_print_char('-');
		aux_int = -1 * n;
		++number_chars_printed;
	}
	else
		aux_int = n;
	if (aux_int > 9)
		number_chars_printed += ft_print_nbr(aux_int / 10);
	ft_print_char(aux_int % 10 + '0');
	++number_chars_printed;
	return (number_chars_printed);
}

int	ft_print_nbr_base(unsigned long n, int base)
{
	int		number_chars_printed;
	char	*base_str;

	base_str = "0123456789abcdef";
	number_chars_printed = 0;
	if (n > 9)
		number_chars_printed += ft_print_nbr_base(n / base, base);
	ft_print_char(base_str[n % base]);
	++number_chars_printed;
	return (number_chars_printed);
}
