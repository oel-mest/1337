/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:29 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/30 15:34:44 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_inset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		s1_len;
	size_t		start;
	size_t		end;
	size_t		new_len;
	char		*trimmed;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	s1_len = ft_strlen (s1);
	start = 0;
	end = s1_len - 1;
	while (s1[start] && ft_inset (s1[start], set))
	{
		start++;
	}
	while (end >= start && ft_inset (s1[end], set))
	{
		end--;
	}
	new_len = end - start + 1;
	trimmed = ft_substr (s1, start, new_len);
	return (trimmed);
}
