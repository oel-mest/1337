/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:59:14 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/08 19:13:35 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_overflow(long nbr, char last, int sign)
{
	if (sign == 1)
	{
		if (nbr > 922337203685477580
			|| (nbr == 922337203685477580 && last > '7'))
			return (1);
	}
	if (sign == -1)
	{
		if (nbr > 922337203685477580
			|| (nbr == 922337203685477580 && last > '8'))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	long			nbr;
	int				sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isnum (str[i]))
	{
		if (check_overflow(nbr, str[i], sign) && sign == -1)
			return (0);
		if (check_overflow(nbr, str[i], sign) && sign == 1)
			return (-1);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
