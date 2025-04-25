/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:05:22 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/11 13:15:31 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_double_token(const char *input, int *i)
{
	char	*token_value;

	token_value = malloc(3);
	if (!token_value)
	{
		perror("HHHH");
		exit(EXIT_FAILURE);
	}
	token_value[0] = input[*i];
	token_value[1] = input[*i];
	token_value[2] = '\0';
	*i += 2;
	return (token_value);
}

char	*handle_single_token(const char *input, int *i)
{
	char	*token_value;

	token_value = malloc(2);
	if (!token_value)
	{
		perror("HHHH");
		exit(EXIT_FAILURE);
	}
	token_value[0] = input[*i];
	token_value[1] = '\0';
	(*i)++;
	return (token_value);
}

char	*get_double_redir(const char *input, int *i, int *token_type)
{
	char	*token_value;

	token_value = malloc(3);
	if (!token_value)
	{
		perror("HHHH");
		exit(EXIT_FAILURE);
	}
	token_value[0] = input[*i];
	token_value[1] = input[*i];
	token_value[2] = '\0';
	if (input[*i] == '<')
		*token_type = TOKEN_HEREDOC;
	else
		*token_type = TOKEN_APPEND;
	*i += 2;
	return (token_value);
}

char	*get_single_redir(const char *input, int *i, int *token_type)
{
	char	*token_value;

	token_value = malloc(2);
	if (!token_value)
	{
		perror("HHHH");
		exit(EXIT_FAILURE);
	}
	token_value[0] = input[*i];
	token_value[1] = '\0';
	if (input[*i] == '<')
		*token_type = TOKEN_REDIRECT_IN;
	else
		*token_type = TOKEN_REDIRECT_OUT;
	(*i)++;
	return (token_value);
}
