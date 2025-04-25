/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:53 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// expand line function
/*
 * Expand an entire command line.
 * This function tokenizes the input by whitespace, expands each token,
 * and then rejoins them with a single space.
 */
/* Helper: Extract the next whitespace‐delimited token from the input string.
   Advances the pointer pointed to by p. */
static char	*extract_next_token(const char **p)
{
	const char	*start;
	size_t		len;
	char		*token;

	while (**p && ((**p == ' ') || (**p == '\t')))
		(*p)++;
	if (!(**p))
		return (NULL);
	start = *p;
	while (**p && ((**p != ' ') && (**p != '\t')))
		(*p)++;
	len = *p - start;
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	ft_strncpy(token, start, len);
	token[len] = '\0';
	return (token);
}

/* Helper: Append an expanded token to the result string.
   Updates pos and cap accordingly. Returns 0 on success, 1 on error. */
static int	append_expanded_token(char **result, size_t *pos, size_t *cap,
		const char *expanded)
{
	size_t		exp_len;
	char		*temp;

	exp_len = ft_strlen(expanded);
	if ((*pos) + exp_len + 2 > (*cap))
	{
		*cap = (*pos) + exp_len + 1024;
		temp = realloc(*result, *cap);
		if (!temp)
		{
			perror("HHHH");
			return (1);
		}
		*result = temp;
	}
	if ((*pos) > 0)
	{
		(*result)[*pos] = ' ';
		*pos = *pos + 1;
		(*result)[*pos] = '\0';
	}
	ft_strcat(*result, expanded);
	*pos = *pos + exp_len;
	return (0);
}

/* Helper: Process the input line by extracting, expanding, and
	appending tokens.
    Returns 0 on success, 1 on error.
*/
static int	process_line_loop(const char *line, char **result, size_t *pos,
		size_t *cap)
{
	const char	*p;
	char		*token;
	char		*expanded;

	p = line;
	while (*p)
	{
		token = extract_next_token(&p);
		if (!token)
			break ;
		expanded = expand_token(token);
		free(token);
		if (!expanded)
			return (1);
		if (append_expanded_token(result, pos, cap, expanded))
		{
			free(expanded);
			return (1);
		}
		free(expanded);
	}
	return (0);
}

/* Main function: Expand a line by processing and expanding each token.
   Frees the input line and returns a new string with the expanded result,
   or NULL if no tokens were found or on error. */
char	*expand_line(char *line)
{
	char		*result;
	size_t		cap;
	size_t		pos;
	int			ret;

	if (!line)
		return (NULL);
	cap = 1024;
	pos = 0;
	result = malloc(cap);
	if (!result)
	{
		perror("HHHH");
		return (NULL);
	}
	result[0] = '\0';
	ret = process_line_loop(line, &result, &pos, &cap);
	free(line);
	if (ret || pos == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
