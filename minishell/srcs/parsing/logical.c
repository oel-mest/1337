/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:42:58 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/07 15:33:24 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_ast	*process_logical_connector(t_token **tokens,
					int inpar, t_ast *left)
{
	t_ast		*node;
	t_ast		*right;
	t_node_type	node_type;

	if ((*tokens)->type == TOKEN_AND)
		node_type = NODE_AND;
	else
		node_type = NODE_OR;
	*tokens = (*tokens)->next;
	if (*tokens == NULL || is_special_token(*tokens))
	{
		if (*tokens == NULL)
			print_error("syntax error near unexpected token `newline\'", NULL);
		else
			print_error("syntax error near unexpected token `",
				(*tokens)->value, "\'", NULL);
		return (free_ast(left), set_status(258), NULL);
	}
	node = create_ast_node(node_type, inpar);
	right = handle_parentheses(tokens, inpar);
	if (right == NULL)
		return (free_ast(node), NULL);
	node->left = left;
	node->right = right;
	return (node);
}

static t_ast	*process_logical_pipeline(t_token **tokens,
					int inpar, t_ast *left)
{
	t_ast	*node;

	node = create_ast_node(NODE_PIPE, inpar);
	node->left = left;
	*tokens = (*tokens)->next;
	node->right = parse_logical(tokens, inpar);
	if (node->right == NULL)
	{
		free_ast(node);
		return (NULL);
	}
	return (node);
}

t_ast	*parse_logical(t_token **tokens, int inpar)
{
	t_ast	*left;
	t_ast	*node;

	left = handle_parentheses(tokens, inpar);
	if (left == NULL)
		return (NULL);
	while (*tokens && ((*tokens)->type == TOKEN_AND
			|| (*tokens)->type == TOKEN_OR))
	{
		node = process_logical_connector(tokens, inpar, left);
		if (node == NULL)
			return (NULL);
		left = node;
	}
	if (*tokens && (*tokens)->type == TOKEN_PIPE)
	{
		node = process_logical_pipeline(tokens, inpar, left);
		if (node == NULL)
			return (NULL);
		left = node;
	}
	return (left);
}

t_ast	*parse(t_token *tokens)
{
	t_ast	*result ;

	result = parse_logical(&tokens, 0);
	if (result == NULL)
		return (NULL);
	if (tokens != NULL)
	{
		print_error("syntax error near unexpected token `",
			tokens->value, "\'", NULL);
		set_status(258);
		free_ast(result);
		return (NULL);
	}
	return (result);
}
