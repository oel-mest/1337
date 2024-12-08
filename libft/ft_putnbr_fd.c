/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:27:55 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/24 13:08:24 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(-n);
		ft_putchar_fd ('-', fd);
	}
	else
		nbr = (unsigned int)n;
	if (nbr < 10)
		ft_putchar_fd (nbr + '0', fd);
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd (nbr % 10 + '0', fd);
	}
}
