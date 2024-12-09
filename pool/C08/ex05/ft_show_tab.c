/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:56:17 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/16 16:08:10 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putsize(int n)
{
	if (n < 10)
	{
		ft_putchar (n + '0');
	}
	else
	{
		ft_putsize (n / 10);
		ft_putchar ((n % 10) + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr (par[i].str);
		ft_putsize (par[i].size);
		ft_putchar ('\n');
		ft_putstr (par[i].copy);
		i++;
	}
}
