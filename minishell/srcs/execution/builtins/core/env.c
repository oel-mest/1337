/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:02:37 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:25 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	builtin_env(t_envnode *envp)
{
	while (envp)
	{
		if (envp->value && (ft_strcmp(envp->value, "") != 0))
			printf("%s=%s\n", envp->var, envp->value);
		envp = envp->next;
	}
	return (0);
}
