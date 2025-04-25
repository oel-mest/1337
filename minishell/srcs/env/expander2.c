/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:16:24 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/12 15:30:12 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// expand_env_vars2 function
static void	process_split_word(char *word, char **new_args, int *new_index)
{
	char	**resplit;
	int		k;

	if (ft_strchr(word, ' '))
	{
		resplit = ft_split_quotes(word);
		k = 0;
		while (resplit[k])
		{
			new_args[*new_index] = ft_strdup(resplit[k]);
			(*new_index)++;
			k++;
		}
		free_split(resplit);
	}
	else
	{
		new_args[*new_index] = ft_strdup(word);
		(*new_index)++;
	}
}

static void	process_arg(char *arg, t_envnode *env_list, char **new_args,
		int *new_index)
{
	char	*expanded;
	char	**split_words;
	int		j;

	expanded = process_expansion(arg, env_list);
	split_words = ft_split(expanded, ' ');
	free(expanded);
	j = 0;
	while (split_words && split_words[j])
	{
		process_split_word(split_words[j], new_args, new_index);
		j++;
	}
	free_split(split_words);
}

char	**expand_env_vars2(char **args, t_envnode *env_list)
{
	int		i;
	int		new_index;
	char	**new_args;

	if (!args)
		return (NULL);
	new_args = malloc(sizeof(char *) * 1024);
	if (!new_args)
		return (NULL);
	i = 0;
	new_index = 0;
	while (args[i])
	{
		process_arg(args[i], env_list, new_args, &new_index);
		i++;
	}
	new_args[new_index] = NULL;
	free_split(args);
	return (new_args);
}
