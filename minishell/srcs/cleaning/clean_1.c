/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:30:15 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/03 13:12:00 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env_list(t_envnode *env_list)
{
	t_envnode	*next;

	while (env_list)
	{
		next = env_list->next;
		free(env_list->var);
		free(env_list->value);
		free(env_list);
		env_list = next;
	}
}

void	free_env_list2(t_envnode **env_list)
{
	t_envnode	*next;

	while (*env_list)
	{
		next = (*env_list)->next;
		free((*env_list)->var);
		free((*env_list)->value);
		free(*env_list);
		*env_list = next;
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = next;
	}
}

void	free_output_list(t_output *output_list)
{
	t_output	*next;

	while (output_list)
	{
		next = output_list->next;
		if (output_list->file != NULL)
			free(output_list->file);
		if (output_list != NULL)
			free(output_list);
		output_list = next;
	}
}

void	free_redi(t_redi *redi)
{
	if (!redi)
		return ;
	free_output_list(redi->input);
	free_output_list(redi->output);
	free_output_list(redi->heredoc);
	free(redi);
}
