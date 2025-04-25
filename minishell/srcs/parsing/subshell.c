/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:38:13 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/07 15:40:15 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_ast	*parse_subshell_content(t_token **tokens, int inpar)
{
	t_ast	*ast;

	ast = create_ast_node(NODE_SUB, inpar);
	ast->left = parse_logical(tokens, 1);
	if (!ast->left)
	{
		free_ast(ast);
		return (NULL);
	}
	return (ast);
}

static t_ast	*handle_parentheses_parent(t_token **tokens, int inpar)
{
	t_ast	*ast;

	*tokens = (*tokens)->next;
	if (!*tokens || (*tokens)->type == TOKEN_RPAREN
		|| is_special_token(*tokens))
	{
		if (!*tokens)
			print_error("syntax error near unexpected token `newline\'", NULL);
		else
			print_error("syntax error near unexpected token `",
				(*tokens)->value, "\'", NULL);
		set_status(258);
		return (NULL);
	}
	ast = parse_subshell_content(tokens, inpar);
	if (!ast)
		return (NULL);
	if (!*tokens || (*tokens)->type != TOKEN_RPAREN)
	{
		print_error("unclosed parentheses", NULL);
		free_ast(ast);
		return (set_status(258), NULL);
	}
	*tokens = (*tokens)->next;
	return (ast);
}

static int	parse_redirection(t_token **tokens, t_ast *ast)
{
	while (*tokens && is_redirection_token(*tokens))
	{
		if (parse_single_redirection(tokens, ast->redi))
		{
			free_ast(ast);
			return (1);
		}
	}
	return (0);
}

static t_ast	*process_redirections(t_token **tokens, t_ast *ast)
{
	while (*tokens && is_redirection_token(*tokens))
	{
		if (parse_redirection(tokens, ast))
			return (NULL);
	}
	return (ast);
}

t_ast	*handle_parentheses(t_token **tokens, int inpar)
{
	t_ast	*ast;

	if (!*tokens)
		return (NULL);
	if (*tokens && (*tokens)->type == TOKEN_LPAREN)
		ast = handle_parentheses_parent(tokens, inpar);
	else if (!*tokens)
	{
		print_error("syntax error", NULL);
		set_status(258);
		return (NULL);
	}
	else
		ast = parse_pipeline(tokens, inpar);
	if (!ast)
		return (NULL);
	return (process_redirections(tokens, ast));
}
