/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:21:46 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:54 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

typedef struct s_pipe_ctx
{
	int			pipefd[2];
	t_ast		*left;
	t_ast		*right;
	t_envnode	**envp;
	pid_t		pid1;
	pid_t		pid2;
}	t_pipe_ctx;

static void	child_process_left(int pipefd[2], t_ast *left, t_envnode **envp)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execute_ast(left, envp);
	exit(0);
}

static void	child_process_right(int pipefd[2], t_ast *right, t_envnode **envp)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	execute_ast(right, envp);
	exit(0);
}

static void	create_pipe_children(t_pipe_ctx *ctx)
{
	ctx->pid1 = fork();
	if (ctx->pid1 == -1)
	{
		print_error("fork", NULL);
		exit(1);
	}
	if (ctx->pid1 == 0)
		child_process_left(ctx->pipefd, ctx->left, ctx->envp);
	ctx->pid2 = fork();
	if (ctx->pid2 == -1)
	{
		print_error("fork", NULL);
		exit(1);
	}
	if (ctx->pid2 == 0)
		child_process_right(ctx->pipefd, ctx->right, ctx->envp);
}

int	execute_pipe(t_ast *left, t_ast *right, t_envnode **envp)
{
	t_pipe_ctx	ctx;
	int			status;

	if (pipe(ctx.pipefd) == -1)
	{
		print_error("pipe", NULL);
		return (1);
	}
	ctx.left = left;
	ctx.right = right;
	ctx.envp = envp;
	create_pipe_children(&ctx);
	close(ctx.pipefd[0]);
	close(ctx.pipefd[1]);
	waitpid(ctx.pid1, &status, 0);
	waitpid(ctx.pid2, &status, 0);
	return (0);
}
