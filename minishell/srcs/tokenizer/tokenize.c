/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:51:59 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/03 15:49:01 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	skip_spaces(const char *input, int *i, int *has_space)
{
	while (input[*i] && isspace(input[*i]))
	{
		*has_space = 1;
		(*i)++;
	}
}

static int	process_token(const char *input, int *i, t_token **tokens,
				int *has_space)
{
	if (input[*i] == '\'' || input[*i] == '"')
	{
		if (handle_quotes(input, i, tokens, has_space))
			return (1);
	}
	else if (input[*i] == '(' || input[*i] == ')'
		|| input[*i] == '|' || input[*i] == '&'
		|| input[*i] == '<' || input[*i] == '>')
	{
		return (handle_special_tokens(input, i, tokens, has_space));
	}
	else
		handle_word(input, i, tokens, has_space);
	return (0);
}

t_token	*tokenize(const char *input)
{
	t_token	*tokens;
	int		i;
	int		has_space;

	tokens = NULL;
	i = 0;
	has_space = 0;
	while (input[i])
	{
		skip_spaces(input, &i, &has_space);
		if (!input[i])
			break ;
		if (process_token(input, &i, &tokens, &has_space))
		{
			free_tokens(tokens);
			return (NULL);
		}
	}
	return (tokens);
}
