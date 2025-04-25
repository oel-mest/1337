/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambuguous_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:18:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:58 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;
	char	in_quote;

	count = 0;
	i = 0;
	in_quote = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			if (in_quote == 0)
				in_quote = s[i];
			else if (in_quote == s[i])
				in_quote = 0;
		}
		if (s[i] == c && in_quote == 0)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

// check if the file is in the env list
static int	in_env(char *file, t_envnode *env_list)
{
	t_envnode	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, file + 1) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// function check if the file name has only spaces or tabs
static int	is_empty_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] != ' ' && file[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	if_ambiguous(char *file, t_envnode *env_list)
{
	char	*var;

	if (count_words(file, ' ') > 1)
		return (1);
	if (!in_env(file, env_list))
		return (1);
	var = ft_getenv(file, env_list);
	if (is_empty_file(var))
		return (1);
	free(var);
	return (0);
}
