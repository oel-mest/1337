/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:22:28 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/03 14:01:54 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_special_token(t_token *token)
{
	return (token->type == TOKEN_AND
		|| token->type == TOKEN_OR
		|| token->type == TOKEN_PIPE);
}

int	is_redirection_token(t_token *token)
{
	return (token->type == TOKEN_REDIRECT_OUT
		|| token->type == TOKEN_REDIRECT_IN
		|| token->type == TOKEN_APPEND
		|| token->type == TOKEN_HEREDOC);
}

int	is_word_or_quote(t_token_type type)
{
	return (type == TOKEN_WORD || type == SINGLE_Q || type == DOUBLE_Q);
}
