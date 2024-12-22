/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:28:31 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 22:00:52 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_words(char *str, char c)
{
	int	in_word;
	int	i;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

void	*free_split(char **strs, int count)
{
	int	k;

	k = 0;
	while (k < count)
	{
		free (strs[k]);
		k++;
	}
	free (strs);
	return ((void *) NULL);
}

int	add_string(char **strs, char *str, int start, int len)
{
	*strs = ft_substr(str, start, len);
	if (!(*strs))
		return (0);
	return (1);
}

char	**ft_split(char *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		start;

	strs = malloc ((ft_count_words (str, c) + 1) * sizeof (char *));
	i = 0;
	j = 0;
	if (!str || !strs)
		return (free_split (strs, 0));
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > start && !add_string(&strs[j], str, start, i - start))
			return (free_split(strs, j));
		if (i > start)
			j++;
	}
	strs[j] = NULL;
	return (strs);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc (len + 1);
	if (!substr)
		return (NULL);
	if (len > 0)
		ft_strlcpy(substr, s + start, len + 1);
	else
		substr[0] = '\0';
	return (substr);
}
