/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:20:29 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/03 13:54:28 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// count words in string s separated by c (not in quotes)
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	in_quote;

	count = 0;
	i = 0;
	in_quote = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			if (in_quote == 0)
				in_quote = s[i];
			else if (in_quote == s[i])
				in_quote = 0;
		}
		if (s[i] == c && in_quote == 0)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char	**free_table(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (j > 0)
		free(tab[--j]);
	free(tab);
	return (NULL);
}

static char	*extract_word(const char *s, char c, size_t *i)
{
	size_t	a;
	char	in_quote;
	char	*word;

	in_quote = 0;
	while (s[*i] == c && !in_quote)
		(*i)++;
	a = *i;
	while (s[*i] != '\0' && (in_quote || s[*i] != c))
	{
		if (s[*i] == '"' || s[*i] == '\'')
		{
			if (!in_quote)
				in_quote = s[*i];
			else if (in_quote == s[*i])
				in_quote = 0;
		}
		(*i)++;
	}
	word = ft_substr(s, a, *i - a);
	return (word);
}

static char	**fill_table(char **tab, const char *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	char	*word;

	i = 0;
	j = 0;
	while (count > 0)
	{
		word = extract_word(s, c, &i);
		if (!word)
			return (free_table(tab, j));
		tab[j++] = word;
		count--;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (fill_table(tab, s, c, count));
}
