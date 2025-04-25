/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:04:36 by mel-mora          #+#    #+#             */
/*   Updated: 2024/11/03 16:32:59 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = len(n);
	sign = 1;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	result = (char *)malloc(count + 1);
	if (!result)
		return (NULL);
	result[count] = '\0';
	while (count-- != 0)
	{
		result[count] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
