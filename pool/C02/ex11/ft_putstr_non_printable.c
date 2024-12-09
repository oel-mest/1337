/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:29:52 by oel-mest          #+#    #+#             */
/*   Updated: 2024/08/30 21:48:30 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_puthex(char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar ('\\');
	ft_putchar (base[(unsigned char)c / 16]);
	ft_putchar (base[(unsigned char)c % 16]);
}

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_printable (str[i]))
			ft_putchar (str[i]);
		else
			ft_puthex (str[i]);
		i++;
	}
}
