/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:03:36 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/11 13:21:54 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*extract_quoted_substr(const char *input, int *i, char quote)
{
	int		start;
	int		length;
	char	*substr;

	start = *i;
	(*i)++;
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] != quote)
	{
		print_error("syntax error (unclosed quote)", NULL);
		return (NULL);
	}
	length = *i - start + 1;
	substr = malloc(length + 1);
	if (!substr)
	{
		perror("HHHH");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(substr, input + start, length);
	substr[length] = '\0';
	(*i)++;
	return (substr);
}

int	handle_quotes(const char *input, int *i, t_token **tokens, int *has_space)
{
	char	quote;
	char	*substr;
	int		token_type;

	quote = input[*i];
	substr = extract_quoted_substr(input, i, quote);
	if (!substr)
		return (1);
	if (quote == '"')
		token_type = DOUBLE_Q;
	else
		token_type = SINGLE_Q;
	append_token(tokens, create_token(substr, token_type, *has_space));
	free(substr);
	*has_space = 0;
	return (0);
}
