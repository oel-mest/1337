/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:54:57 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:40 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// export env in our node list (dosnt use strtok) with msg of error
t_envnode	*find_env_var(t_envnode *envp, const char *var)
{
	while (envp)
	{
		if (ft_strcmp(envp->var, var) == 0)
			return (envp);
		envp = envp->next;
	}
	return (NULL);
}

// export env in our node list (dosnt use strtok) with msg of error
int	is_valid_var_name(const char *var)
{
	int	i;

	if (!var || (!isalpha(var[0]) && var[0] != '_'))
		return (0);
	i = 1;
	while (var[i])
	{
		if (!isalnum(var[i]) && var[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// remove first and last quotes if they exist
void	hundle(char **home)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*home);
	if (len >= 2 && ((*home[0] == '"' && (*home)[len - 1] == '"')
		|| ((*home)[0] == '\'' && (*home)[len - 1] == '\'')))
	{
		tmp = ft_strndup(*home + 1, len - 2);
		free(*home);
		*home = tmp;
	}
}

// remove first and last quotes if they exist
void	set_pwd_oldpwd(t_envnode **envp, char *oldpwd)
{
	char	*pwd;
	char	*join;

	pwd = getcwd(NULL, 0);
	join = ft_strjoin("OLDPWD=", oldpwd);
	builtin_export((char *[]){"export", join, NULL}, envp);
	free(join);
	join = ft_strjoin("PWD=", pwd);
	builtin_export((char *[]){"export", join, NULL}, envp);
	free(join);
	free(oldpwd);
	free(pwd);
}
