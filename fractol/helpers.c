/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:39:59 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/04 14:41:31 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

double	ft_atof(char *str)
{
	double	part1;
	double	part2;
	int		sign;
	double	divisor;

	part1 = 0.0;
	part2 = 0.0;
	sign = 1;
	divisor = 1.0;
	if (*str && (*str == '-' || *str == '+'))
		if (*(str++) == '-')
			sign *= -1;
	while (is_digit(*str))
		part1 = (part1 * 10) + *(str++) - '0';
	if (*str == '.')
		str++;
	while (is_digit(*str))
	{
		divisor *= 10.0;
		part2 = (part2 * 10) + *str - '0';
		str++;
	}
	return (sign * (part1 + part2 / divisor));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	scale(int value, double min, double max, int end)
{
	return (min + (max - min) * (value) / (double)(end));
}
