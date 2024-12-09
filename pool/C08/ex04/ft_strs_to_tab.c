/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:54:19 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/09 16:12:35 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	cpy = (char *)malloc(len + 1);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*str_elem;

	str_elem = malloc (sizeof(t_stock_str) * (ac + 1));
	if (!str_elem)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		str_elem[i].size = ft_strlen (av[i]);
		str_elem[i].str = av[i];
		str_elem[i].copy = ft_strdup (av[i]);
		i++;
	}
	str_elem[i].str = 0;
	return (str_elem);
}
