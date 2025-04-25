/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:19:02 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/05 16:02:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*append_char2(char *str, char c)
{
	char	mystr[2];
	char	*new_str;

	mystr[0] = c;
	mystr[1] = 0;
	new_str = ft_strjoin(str, mystr);
	free(str);
	return (new_str);
}

char	*handle_var_expansion(char *args, int *i, t_envnode *env_list)
{
	char	*result;
	int		start;
	char	*var_name;

	result = NULL;
	if (args[*i] == '?')
	{
		(*i)++;
		result = handle_lstatus_var();
	}
	else if (isalnum(args[*i]) || args[*i] == '_')
	{
		start = *i - 1;
		while (args[*i] && (isalnum(args[*i]) || args[*i] == '_'))
			(*i)++;
		var_name = ft_strndup(args + start, *i - start);
		result = ft_getenv(var_name, env_list);
		free(var_name);
	}
	else
		result = ft_strdup("$");
	return (result);
}

void	update_quotes(char c, int *in_single_quote, int *in_double_quote)
{
	if (c == '\'' && !(*in_double_quote))
		*in_single_quote = !(*in_single_quote);
	if (c == '"' && !(*in_single_quote))
		*in_double_quote = !(*in_double_quote);
}

char	*process_dollar(const char *args, int *i, char *result,
								t_envnode *env_list)
{
	char	*var_value;
	char	*new_result;

	(*i)++;
	var_value = handle_var_expansion((char *)args, i, env_list);
	if (var_value)
	{
		new_result = ft_strjoin(result, var_value);
		free(result);
		free(var_value);
		return (new_result);
	}
	return (result);
}
