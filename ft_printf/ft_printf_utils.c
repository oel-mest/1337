/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:03:32 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/06 17:03:32 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(va_list args, char type)
{
	int	total_written;

	total_written = 0;
	if (type == 'c')
		total_written += print_c (va_arg (args, int));
	if (type == 's')
		total_written += print_s (va_arg (args, char *));
	if (type == 'p')
		total_written += print_p (va_arg (args, void *));
	if (type == 'd' || type == 'i')
		total_written += print_d (va_arg (args, int));
	if (type == 'u')
		total_written += print_u (va_arg (args, unsigned int));
	if (type == 'x' || type == 'X')
		total_written += print_x (va_arg (args, unsigned int), type);
	if (type == '%')
		total_written += write (1, &type, 1);
	return (total_written);
}

int	print_c(int c)
{
	unsigned char	x;

	x = (unsigned char)c;
	return (write (1, &x, 1));
}

int	print_s(char *str)
{
	int	printed_count;

	printed_count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		printed_count += print_c(*str);
		str++;
	}
	return (printed_count);
}

int	print_d(int d)
{
	int	nbr;
	int	printed_count;

	if (d == -2147483648)
		return (print_s("-2147483648"));
	printed_count = 0;
	if (d < 0)
	{
		printed_count += print_c ('-');
		nbr = (-d);
	}
	else
		nbr = d;
	if (nbr < 10)
	{
		printed_count += print_c ('0' + nbr);
		return (printed_count);
	}
	printed_count += print_d (nbr / 10);
	printed_count += print_c ('0' + (nbr % 10));
	return (printed_count);
}

int	print_u(unsigned int d)
{
	int	printed_count;

	printed_count = 0;
	if (d < 10)
	{
		printed_count += print_c ('0' + d);
		return (printed_count);
	}
	printed_count += print_u (d / 10);
	printed_count += print_c ('0' + (d % 10));
	return (printed_count);
}
