/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:35:17 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 20:36:00 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write (fd, s++, 1);
	write (fd, "\n", 1);
}

int	ft_isspace(char c)
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

int	ft_count_words(char *str, char c)
{
	int	in_word;
	int	i;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}
