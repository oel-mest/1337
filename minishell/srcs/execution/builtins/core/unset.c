/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:00:00 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:35 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	unset_one_var(char *var, t_envnode **envp)
{
	t_envnode	*prev;
	t_envnode	*tmp;

	prev = NULL;
	tmp = *envp;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, var) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*envp = tmp->next;
			free(tmp->var);
			free(tmp->value);
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (0);
}

int	builtin_unset(char **args, t_envnode **envp)
{
	int	i;

	if (!envp || !*envp)
		return (1);
	i = 0;
	while (args[++i])
	{
		if (!is_valid_var_name(args[i]))
		{
			print_error("unset: ", args[i],
				": not a valid identifier", NULL);
			set_status(1);
			return (1);
		}
		unset_one_var(args[i], envp);
	}
	return (0);
}
