/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:04:17 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:00 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	exec_command_node(t_ast *node, t_envnode **envp)
{
	return (execute_command(node, envp));
}

int	exec_pipe_node(t_ast *node, t_envnode **envp)
{
	if (execute_pipe(node->left, node->right, envp) != 0)
		return (1);
	return (0);
}

int	exec_and_node(t_ast *node, t_envnode **envp)
{
	if (execute_ast(node->left, envp) == 0)
		return (execute_ast(node->right, envp));
	return (0);
}

int	exec_or_node(t_ast *node, t_envnode **envp)
{
	if (execute_ast(node->left, envp) != 0)
		return (execute_ast(node->right, envp));
	return (0);
}

int	exec_sub_node(t_ast *node, t_envnode **envp)
{
	set_status(execute_subshell(node, envp));
	return (get_status());
}
