/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:04:08 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/11 13:15:35 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_word_char(char c)
{
	if (!c)
		return (0);
	if (isspace(c))
		return (0);
	if (c == '|' || c == '<' || c == '>' || c == '&'
		|| c == '\'' || c == '"' || c == '(' || c == ')')
		return (0);
	return (1);
}

void	handle_word(const char *input, int *i, t_token **tokens, int *has_space)
{
	int		start;
	int		length;
	char	*word;

	start = *i;
	while (input[*i] && is_word_char(input[*i]))
		(*i)++;
	length = *i - start;
	if (length > 0)
	{
		word = malloc(length + 1);
		if (!word)
		{
			perror("HHHH");
			exit(EXIT_FAILURE);
		}
		ft_strncpy(word, input + start, length);
		word[length] = '\0';
		append_token(tokens, create_token(word, TOKEN_WORD, *has_space));
		free(word);
		*has_space = 0;
	}
}
