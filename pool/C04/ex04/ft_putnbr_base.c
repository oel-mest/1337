/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:30:37 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/08 14:49:09 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str);

int	ft_isvalid(char *str)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	len = ft_strlen (str);
	if (len < 2)
		return (0);
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '-' || str[i] == '+' || str[i] <= 32 || str[i] > 126)
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	n;

	len = 0;
	if (ft_isvalid (base))
	{
		len = ft_strlen (base);
		if (nbr < 0)
		{
			ft_putchar ('-');
			n = nbr * (-1);
		}
		else
			n = nbr;
		if (n >= len)
			ft_putnbr_base (n / len, base);
		ft_putchar (base[n % len]);
	}
}
