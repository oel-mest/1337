/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:55:57 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:46 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	handle_empty_path(t_exec_ctx *ctx)
{
	size_t	len;
	char	*current_dir_exec;

	len = ft_strlen(ctx->args[0]) + 3;
	current_dir_exec = malloc(len);
	if (!current_dir_exec)
	{
		perror("HHHH");
		exit(1);
	}
	ft_strcpy(current_dir_exec, "./");
	ft_strcat(current_dir_exec, ctx->args[0]);
	if (access(current_dir_exec, F_OK) == 0)
		execute_local_executable(current_dir_exec, ctx->args, ctx->envp_array);
	print_error(ctx->args[0], ": No such file or directory", NULL);
	if (ctx->args)
		free(ctx->args);
	if (ctx->path)
		free(ctx->path);
	exit(127);
}

static void	child_handle_no_path(t_exec_ctx *ctx)
{
	char	*path0;

	path0 = ft_getenv("$PATH", *(ctx->envp));
	if (!path0)
	{
		handle_empty_path(ctx);
	}
	print_error(ctx->args[0], ": command not found", NULL);
	if (ctx->args)
		free_split(ctx->args);
	if (ctx->cmd->args)
		free(ctx->cmd->args);
	if (ctx->path)
		free(ctx->path);
	if (path0)
		free(path0);
	exit(127);
}

void	child_process(t_exec_ctx *ctx)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (ctx->cmd->input2)
	{
		if (redirect_input(ctx->cmd->input2))
			exit(1);
	}
	if (ctx->cmd->output2)
	{
		if (redirect_output(ctx->cmd->output2, ctx->cmd->append))
			exit(1);
	}
	if (ft_strncmp(ctx->args[0], "./", 2) == 0)
		execute_local_executable(ctx->args[0], ctx->args, ctx->envp_array);
	else if (ctx->path) 
		execve(ctx->path, ctx->args, ctx->envp_array);
	else
		child_handle_no_path(ctx);
}
