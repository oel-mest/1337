/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:38 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:30 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	process_export_arg_eq(char *arg, t_envnode **envp)
{
	size_t	var_len;
	char	*var_name;
	int		valid;

	var_name = extract_var_name(arg, &var_len);
	if (var_name == NULL)
	{
		print_error("malloc", NULL);
		exit(EXIT_FAILURE);
	}
	valid = is_valid_var_name(var_name);
	if (valid == 0)
	{
		print_error("minishell: export: ", var_name,
			": not a valid identifier", NULL);
		free(var_name);
		set_status(1);
		return (1);
	}
	update_export_var(var_name, arg, envp);
	free(var_name);
	return (0);
}

static int	process_export_arg(char *arg, t_envnode **envp)
{
	char	*eq;

	if (arg[0] == '=')
	{
		print_error("minishell: export: ", arg,
			": not a valid identifier", NULL);
		set_status(1);
		return (1);
	}
	eq = ft_strchr(arg, '=');
	if (eq == NULL)
		return (process_export_arg_no_eq(arg, envp));
	return (process_export_arg_eq(arg, envp));
}

int	builtin_export(char **args, t_envnode **envp)
{
	int	i;
	int	ret;

	if (envp == NULL)
		return (1);
	print_env_export(*envp, args);
	i = 0;
	while (args[++i] != NULL)
	{
		ret = process_export_arg(args[i], envp);
		if (ret != 0)
			return (1);
	}
	set_status(0);
	return (0);
}
