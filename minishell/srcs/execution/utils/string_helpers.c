/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:39:42 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:45 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	find_matching_quote(char *input, int i, char quote)
{
	while (input[i] && input[i] != quote)
		i++;
	return (i);
}

char	*process_initial_part(char *input, int *i)
{
	char	quote;
	char	*result;
	int		end;

	*i = 0;
	result = ft_strdup("");
	if (input[*i] == '\'' || input[*i] == '"')
	{
		quote = input[*i];
		(*i)++;
		end = find_matching_quote(input, *i, quote);
		if (input[end + 1] == '\0')
		{
			free(result);
			return (input);
		}
		free(result);
		result = ft_substr(input, 1, end - 1);
		*i = end + 1;
	}
	return (result);
}

void	process_remaining_chars(char *input, int *i, char **result)
{
	char	quote;

	while (input[*i])
	{
		if (input[*i] == '\'' || input[*i] == '"')
		{
			quote = input[*i];
			*i = *i + 1;
			while (input[*i] && input[*i] != quote)
			{
				append_char(result, input[*i]);
				*i = *i + 1;
			}
			*i = *i + 1;
		}
		else
		{
			append_char(result, input[*i]);
			*i = *i + 1;
		}
	}
}

void	append_char(char **str, char c)
{
	char	mystr[2];
	char	*tmp;

	mystr[0] = c;
	mystr[1] = 0;
	tmp = *str;
	*str = ft_strjoin(*str, mystr);
	if (tmp)
		free(tmp);
}
