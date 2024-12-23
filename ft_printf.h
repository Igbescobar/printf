/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:56:12 by igngonza          #+#    #+#             */
/*   Updated: 2024/12/22 11:34:47 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *s, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int nb);
int	ft_print_nbr_base(unsigned long nb, int base);
int	ft_print_ptr(unsigned long ptr);

#endif