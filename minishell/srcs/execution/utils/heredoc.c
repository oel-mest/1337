/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:35:41 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:30 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	collect_heredoc(t_cmd *cmd, t_envnode **envp)
{
	t_output	*current;

	current = cmd->input2;
	while (current)
	{
		if (current->type == TOKEN_HEREDOC)
			process_heredoc_entry(current, envp);
		current = current->next;
	}
}

void	collect_heredoc2(t_redi *redi, t_envnode **envp)
{
	t_output	*current;

	current = redi->input;
	while (current)
	{
		if (current->type == TOKEN_HEREDOC)
			process_heredoc_entry(current, envp);
		current = current->next;
	}
}

void	handle_heredoc_if_needed(t_cmd *cmd)
{
	t_output	*current;
	int			fd;

	current = cmd->input2;
	while (current && current->type == TOKEN_HEREDOC)
	{
		if (access(current->file, F_OK) == 0)
		{
			fd = open(current->file, O_RDONLY);
			if (fd < 0)
			{
				print_error("open", current->file, NULL);
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else
		{
			print_error("open", current->file, NULL);
			exit(1);
		}
		current = current->next;
	}
}

static void	hundle_errno(int fd, char *file)
{
	if (fd < 0)
	{
		print_error("open", file, NULL);
		exit(1);
	}
}

void	handle_heredoc_if_needed2(t_redi *redi)
{
	t_output	*current;
	int			fd;

	current = redi->input;
	while (current)
	{
		if (current->type == TOKEN_HEREDOC)
		{
			if (access(current->file, F_OK) == 0)
			{
				fd = open(current->file, O_RDONLY);
				hundle_errno(fd, current->file);
				dup2(fd, STDIN_FILENO);
				close(fd);
			}
			else
			{
				print_error("open", current->file, NULL);
				exit(1);
			}
		}
		current = current->next;
	}
}
