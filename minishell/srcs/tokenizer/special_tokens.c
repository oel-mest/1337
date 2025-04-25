/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:04:46 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/11 13:15:18 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_token_parentheses(const char *input, int *i,
				t_token **tokens, int *has_space)
{
	char	*token_value;
	int		token_type;

	token_value = malloc(2);
	if (!token_value)
	{
		perror("HHHH");
		exit(EXIT_FAILURE);
	}
	token_value[0] = input[*i];
	token_value[1] = '\0';
	if (input[*i] == '(')
		token_type = TOKEN_LPAREN;
	else
		token_type = TOKEN_RPAREN;
	append_token(tokens, create_token(token_value, token_type, *has_space));
	free(token_value);
	(*i)++;
	*has_space = 0;
}

static int	handle_pipes_and_logicals(const char *input, int *i,
				t_token **tokens, int *has_space)
{
	char	*token_value;
	int		token_type;

	if (input[*i + 1] == input[*i])
	{
		token_value = handle_double_token(input, i);
		if (input[*i - 2] == '|')
			token_type = TOKEN_OR;
		else
			token_type = TOKEN_AND;
	}
	else if (input[*i] == '|')
	{
		token_value = handle_single_token(input, i);
		token_type = TOKEN_PIPE;
	}
	else
		return (printf("Error: unsupported token &\n"), 1);
	append_token(tokens, create_token(token_value, token_type, *has_space));
	free(token_value);
	*has_space = 0;
	return (0);
}

static void	handle_redirections(const char *input, int *i, t_token **tokens,
				int *has_space)
{
	char	*token_value;
	int		token_type;

	if (input[*i + 1] == input[*i])
	{
		token_value = get_double_redir(input, i, &token_type);
		append_token(tokens, create_token(token_value, token_type, *has_space));
		free(token_value);
	}
	else
	{
		token_value = get_single_redir(input, i, &token_type);
		append_token(tokens, create_token(token_value, token_type, *has_space));
		free(token_value);
	}
	*has_space = 0;
}

int	handle_special_tokens(const char *input, int *i, t_token **tokens,
		int *has_space)
{
	if (input[*i] == '(' || input[*i] == ')')
		handle_token_parentheses(input, i, tokens, has_space);
	else if (input[*i] == '|' || input[*i] == '&')
		return (handle_pipes_and_logicals(input, i, tokens, has_space));
	else if (input[*i] == '<' || input[*i] == '>')
		handle_redirections(input, i, tokens, has_space);
	return (0);
}
