/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:58:38 by mel-mora          #+#    #+#             */
/*   Updated: 2025/03/24 02:21:24 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join(char *newstr, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len_total;

	if (!s1 || !s2)
	{
		if (!s1 && s2)
			return ((char *)s2);
		if (!s2 && s1)
			return ((char *)s1);
		return (NULL);
	}
	len_total = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(len_total + 1);
	if (!newstr)
		return (NULL);
	join(newstr, s1, s2);
	return (newstr);
}
