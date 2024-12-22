/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:28:04 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 21:00:25 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

long	ft_convertl(char *str, int i)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

long	ft_atol(char *str)
{
	long	rez;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	while (ft_isspace (str[i]))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	rez = ft_convertl (str, i);
	return (rez * sign);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write (fd, s++, 1);
	write (fd, "\n", 1);
}
