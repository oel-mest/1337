/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:27:12 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:50 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* Helper: Check if the string is composed entirely of '*' */
int	is_all_stars(const char *s)
{
	while (*s)
	{
		if (*s != '*')
			return (0);
		s++;
	}
	return (1);
}

/*
 * Expand a token: if it contains a '*' then perform wildcard expansion,
 * otherwise simply duplicate the token.
 */
char	*expand_token(const char *token)
{
	char	**matches;
	size_t	total;
	char	*res; 

	if (!ft_strchr(token, '*'))
		return (ft_strdup(token));
	matches = expand_wildcard(token);
	if (!matches || !matches[0])
	{
		if (matches)
			free(matches);
		return (ft_strdup(token));
	}
	total = compute_total(matches);
	res = build_result(matches, total);
	free(matches);
	return (res);
}

/* 
 * Recursively match a pattern against a string.
 * The pattern supports '*' as a wildcard for any number of characters.
 */
int	match_pattern(const char *pattern, const char *str)
{
	if (*pattern == '\0')
		return (*str == '\0');
	if (*pattern == '*')
	{
		if (is_all_stars(pattern))
			return (1);
		while (*(pattern + 1) == '*')
			pattern++;
		while (*str)
		{
			if (match_pattern(pattern + 1, str))
				return (1);
			str++;
		}
		return (match_pattern(pattern + 1, str));
	}
	else
	{
		if (*pattern == *str)
			return (match_pattern(pattern + 1, str + 1));
		return (0);
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
