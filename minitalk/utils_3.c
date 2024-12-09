/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:24:57 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/09 21:11:36 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_realloc(char **str, int taille, int old_taille)
{
	char	*tmp;

	tmp = malloc(taille);
	if (*str == NULL)
	{
		*str = tmp;
		return ;
	}
	ft_memcpy(tmp, *str, old_taille);
	free(*str);
	*str = tmp;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char				*ptr;
	const unsigned char			*s;
	size_t						i;

	if (dst == src)
		return (dst);
	ptr = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return (dst);
}

int	ftput_endl(char **g_str, int *taille)
{
	char	*original;

	original = *g_str;
	*taille = 0;
	while (**g_str)
	{
		write(1, (*g_str)++, 1);
	}
	write(1, "\n", 1);
	free(original);
	*g_str = NULL;
	return (0);
}
