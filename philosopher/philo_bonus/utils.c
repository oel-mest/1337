/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:45:17 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 20:18:28 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static long long	ft_convertl(char *str, int i)
{
	long long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

long long	ft_atol(char *str)
{
	long long	rez;
	int			i;
	int			sign;

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

int	ft_getlen(int n)
{
	int				len;
	unsigned int	nbr;

	len = 1;
	if (n < 0)
	{
		len++;
		nbr = (unsigned int)(-n);
	}
	else
	{
		nbr = (unsigned int)n;
	}
	while (nbr > 9)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*str;
	int				i;

	len = ft_getlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nbr = (unsigned int)(-n);
		str[0] = '-';
	}
	else
		nbr = (unsigned int)n;
	i = len - 1;
	str[len] = '\0';
	while (nbr > 9)
	{
		str[i--] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	str[i] = nbr + '0';
	return (str);
}
