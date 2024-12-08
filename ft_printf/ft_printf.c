/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:03:29 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/06 17:03:29 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_supported(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd'
		|| s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

int	check_valid(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!check_supported(str[++i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	if (!check_valid (str))
		return (-1);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			count += print_type(args, *++str);
			str++;
		}
		else
		{
			count += write(1, str, 1);
			str++;
		}
	}
	va_end(args);
	return (count);
}
