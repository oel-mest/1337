/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:25:09 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/11 13:16:20 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expand_env_vars(char *args, t_envnode *env_list)
{
	char	*result;
	int		i;
	int		in_single_quote;
	int		in_double_quote;

	result = malloc(1);
	i = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	if (!args || !result)
		return (free(result), NULL);
	result[0] = '\0';
	while (args[i])
	{
		update_quotes(args[i], &in_single_quote, &in_double_quote);
		if (args[i] == '$' && !in_single_quote)
			result = process_dollar(args, &i, result, env_list);
		else
			result = append_char2(result, args[i++]);
	}
	if (result[0] == '\0')
		return (NULL);
	return (result);
}

char	*process_expansion(char *arg, t_envnode *env_list)
{
	char	*result;
	int		i;
	int		in_single_quote;
	int		in_double_quote;

	result = malloc(1);
	if (!arg)
		return (NULL);
	i = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	if (!result)
		return (NULL);
	result[0] = '\0';
	while (arg[i])
	{
		update_quotes(arg[i], &in_single_quote, &in_double_quote);
		if (arg[i] == '$' && !in_single_quote)
			result = process_dollar(arg, &i, result, env_list);
		else
			result = append_char2(result, arg[i++]);
	}
	if (result[0] == '\0')
		return (NULL);
	return (result);
}

void	ft_split_quotes_loop(char *str, t_split_state *state,
		char **result, char *word)
{
	while (str[state->k])
	{
		if (str[state->k] == '"' || str[state->k] == '\'')
			state->in_quotes = !(state->in_quotes);
		else if (str[state->k] == ' ' && state->in_quotes == 0)
		{
			word[state->j] = '\0';
			result[state->i] = ft_strdup(word);
			state->i = state->i + 1;
			state->j = 0;
		}
		else
		{
			word[state->j] = str[state->k];
			state->j = state->j + 1;
		}
		state->k = state->k + 1;
	}
	if (state->j > 0)
	{
		word[state->j] = '\0';
		result[state->i] = ft_strdup(word);
		state->i = state->i + 1;
	}
}

char	**ft_split_quotes(char *str)
{
	char			**result;
	char			*word;
	t_split_state	state;

	result = malloc(sizeof(char *) * 1024);
	if (result == NULL)
		return (NULL);
	state.i = 0;
	state.j = 0;
	state.in_quotes = 0;
	state.k = 0;
	word = malloc(1024);
	if (word == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_split_quotes_loop(str, &state, result, word);
	result[state.i] = NULL;
	free(word);
	return (result);
}
