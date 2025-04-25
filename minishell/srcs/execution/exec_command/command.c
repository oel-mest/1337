/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:37:51 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:48 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	g_status = 0;

void	set_status(int status)
{
	g_status = status;
}

int	get_status(void)
{
	return (g_status);
}

void	free_withoutexit(t_exec_ctx *ctx)
{
	if (ctx->args)
		free_split(ctx->args);
	if (ctx->path)
		free(ctx->path);
	if (ctx->envp_array)
		free_split(ctx->envp_array);
}

static int	wait_and_cleanup(t_exec_ctx *ctx)
{
	waitpid(0, &g_status, 0);
	if (WIFSIGNALED(g_status))
	{
		if (WTERMSIG(g_status) == SIGINT)
			set_status(130);
		else if (WTERMSIG(g_status) == SIGQUIT)
			set_status(131);
	}
	else
		set_status(WEXITSTATUS(g_status));
	free_split(ctx->envp_array);
	if (ctx->args)
		free_split(ctx->args);
	if (ctx->path)
		free(ctx->path);
	if (g_status != 0)
		return (1);
	return (0);
}

int	execute_command(t_ast *tree, t_envnode **envp)
{
	t_exec_ctx	ctx;
	int			ret;
	int			pid;

	ret = setup_context(&ctx, tree, envp);
	if (ret == 5)
	{
		free_withoutexit(&ctx);
		return (0);
	}
	if (ret != 0)
		return (ret);
	pid = fork();
	if (pid == -1)
	{
		print_error("fork", NULL);
		return (1);
	}
	ctx.path = search_command(ctx.args[0], *envp);
	ctx.envp_array = envp_to_array(*envp);
	if (pid == 0)
		child_process(&ctx);
	wait_and_cleanup(&ctx);
	return (get_status());
}
