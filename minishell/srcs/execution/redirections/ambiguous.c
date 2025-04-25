/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:57:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:56 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	check_ambiguous_output(t_output *output, t_envnode *env_list)
{
	char	*tmp;

	while (output)
	{
		if (output->file)
		{
			if (output->file[0] != '$')
				return (0);
			else if (if_ambiguous(output->file, env_list))
			{
				print_error(output->file, ": ambiguous redirect", NULL);
				set_status(1);
				return (1);
			}
			else
			{
				tmp = output->file;
				output->file = expand_env_vars(output->file, env_list);
				free(tmp);
			}
		}
		output = output->next;
	}
	return (0);
}

static int	check_ambiguous_input(t_output *heredoc, t_envnode *env_list)
{
	char	*tmp;

	while (heredoc)
	{
		if (heredoc->file && heredoc->type == TOKEN_REDIRECT_IN)
		{
			if (heredoc->file[0] != '$')
				return (0);
			else if (if_ambiguous(heredoc->file, env_list))
			{
				print_error(heredoc->file, ": ambiguous redirect", NULL);
				set_status(1);
			}
			else
			{
				tmp = heredoc->file;
				heredoc->file = expand_env_vars(heredoc->file, env_list);
				free(tmp);
			}
		}
		heredoc = heredoc->next;
	}
	return (0);
}

int	check_ambiguous_redirects(t_cmd *cmd, t_envnode *env_list)
{
	if (check_ambiguous_output(cmd->output2, env_list))
		return (1);
	if (check_ambiguous_input(cmd->input2, env_list))
		return (1);
	return (0);
}
