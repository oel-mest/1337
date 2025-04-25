/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:31:03 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/11 13:50:34 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	free_ast(ast->left);
	free_ast(ast->right);
	if (ast->cmd)
		free_cmd(ast->cmd);
	if (ast->type == NODE_SUB)
		free_redi(ast->redi);
	free(ast);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split || !*split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

// from clean_1.c
void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free(cmd->args);
	free(cmd->heredoc);
	free_output_list(cmd->output2);
	free_output_list(cmd->input2);
	free(cmd);
}
