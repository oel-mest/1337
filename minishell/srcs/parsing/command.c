/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:27:28 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/10 22:47:37 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	process_command_tokens(t_ast *node, t_token **tokens, int inpar)
{
	int	ret;

	while (*tokens)
	{
		ret = process_single_token(node, tokens, inpar);
		if (ret == 1)
			return (1);
		if (ret == 2)
			break ;
	}
	return (0);
}

t_ast	*parse_command(t_token **tokens, int inpar)
{
	t_ast	*node;

	if (*tokens == NULL || is_special_token(*tokens)
		|| (*tokens)->type == TOKEN_RPAREN)
	{
		if (*tokens == NULL)
		{
			print_error("syntax error near unexpected token `newline\'", NULL);
			set_status(258);
		}
		else
		{
			print_error("syntax error near unexpected token `",
				(*tokens)->value, "\'", NULL);
			set_status(258);
		}
		return (NULL);
	}
	node = create_ast_node(NODE_COMMAND, inpar);
	node->cmd = create_cmd_node();
	if (process_command_tokens(node, tokens, inpar))
	{
		return (free_ast(node), NULL);
	}
	return (node);
}

// utils
void	join_output(t_output *output, char *str)
{
	char	*tmp;

	while (output->next)
		output = output->next;
	tmp = output->file;
	output->file = ft_strjoin(output->file, str);
	free(tmp);
}
