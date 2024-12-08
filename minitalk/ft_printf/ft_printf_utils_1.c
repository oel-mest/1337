/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:05:42 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/06 17:21:32 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lx(unsigned long d)
{
	char	*base;
	int		printed_count;

	base = "0123456789abcdef";
	printed_count = 0;
	if (d < 16)
	{
		printed_count += print_c (base[d]);
		return (printed_count);
	}
	printed_count += print_lx (d / 16);
	printed_count += print_c (base[d % 16]);
	return (printed_count);
}

int	print_p(void *ptr)
{
	unsigned long	addr;
	int				printed_count;

	addr = (unsigned long) ptr;
	printed_count = 0;
	printed_count += print_s("0x");
	printed_count += print_lx(addr);
	return (printed_count);
}

int	print_x(unsigned int d, char type)
{
	char	*base;
	int		printed_count;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	printed_count = 0;
	if (d < 16)
	{
		printed_count += print_c (base[d]);
		return (printed_count);
	}
	printed_count += print_x (d / 16, type);
	printed_count += print_c (base[d % 16]);
	return (printed_count);
}
