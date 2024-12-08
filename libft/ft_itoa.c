/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:30:06 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/24 13:34:37 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
