/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:43:14 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/12 12:53:59 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	in_word;
	int	i;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_sep (str[i], charset) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (ft_is_sep (str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*words;
	int		i;
	int		j;
	int		start;

	strs = malloc ((ft_count_words (str, charset) + 1) * sizeof (char *));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep (str[i], charset))
			i++;
		start = i;
		while (str[i] && !ft_is_sep (str[i], charset))
			i++;
		if (i > start)
		{
			words = (char *) malloc (1 + (i - start) * sizeof (char));
			ft_strncpy (words, str + start, i - start);
			strs[j++] = words;
		}
	}
	strs[j] = 0;
	return (strs);
}
/*
int	main()
{
	char	*str = "hello,world,!";
	char	*charset = ",";
	char	**rez;
	int		i = 0;
	printf ("%d  :\n", ft_count_words (str, charset) + 1);
	rez = ft_split (str, charset);
	while (rez[i] != 0)
		printf ("%s\n", rez[i++]);
	return (0);
}*/
