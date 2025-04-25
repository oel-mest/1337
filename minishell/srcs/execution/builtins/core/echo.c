/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:51:14 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:06:17 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	process_n_options(char *args, int start, int *newline)
{
	int	j;

	while (args[start] == '-')
	{
		j = start + 1;
		if (args[j] != 'n')
			break ;
		while (args[j] == 'n')
			j++;
		if (args[j] == ' ' || args[j] == '\0')
		{
			*newline = 0;
			start = j;
			while (args[start] == ' ')
				start++;
		}
		else
			break ;
	}
	return (start);
}

static void	print_args_without_quotes(char *args, int start)
{
	while (args[start])
	{
		if (args[start] != '"' && args[start] != '\'')
			printf("%c", args[start]);
		start++;
	}
}

int	builtin_echo(char *args)
{
	int	newline;
	int	i;

	newline = 1;
	i = 5;
	if (ft_strlen(args) == 4)
		return (printf("\n"), set_status(0), 0);
	while (args[i] == ' ')
		i++;
	i = process_n_options(args, i, &newline);
	print_args_without_quotes(args, i);
	if (newline)
		printf("\n");
	set_status(0);
	return (0);
}
