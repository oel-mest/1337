/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:37:36 by oel-mest          #+#    #+#             */
/*   Updated: 2024/08/29 12:44:28 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(char c)
{
	write (1, &c, 1);
}

void	ft_print_combo2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print ((i / 10) + '0');
			ft_print ((i % 10) + '0');
			ft_print (' ');
			ft_print ((j / 10) + '0');
			ft_print ((j % 10) + '0');
			if (i < 98)
				write (1, ", ", 2);
			j++;
		}
		i++;
	}
}
