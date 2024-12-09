/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:28:48 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/11 17:29:32 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

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

int	ft_total_l(char **strs, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen (strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!src || !dest)
		return (dest);
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len++] = src[i++];
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*rez;
	int		i;

	if (size <= 0)
	{
		rez = (char *)malloc (1);
		rez[0] = '\0';
		return (rez);
	}
	rez = malloc (ft_total_l (strs, size) + ((size - 1) * ft_strlen (sep)) + 1);
	i = 0;
	rez[0] = '\0';
	while (i < size)
	{
		rez = ft_strcat (rez, strs[i]);
		if (i < size - 1)
		{
			rez = ft_strcat (rez, sep);
		}
		i++;
	}
	return (rez);
}
/*
int	main(void)
{
	char	*strings[] = {"Hello", "itsme", "oussama", "test"};
	char	*str;
	char	sepr[3] = ":";
	int		i;

	i = 0;
	str = ft_strjoin(0, strings, sepr);
	printf ("%s", str);
	return (0);
}
*/
