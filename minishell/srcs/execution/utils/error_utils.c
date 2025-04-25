/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:34:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:22 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_error(char *first, ...)
{
	va_list	args;
	char	*str;

	write(2, "HHHH: ", 6);
	va_start(args, first);
	str = first;
	while (str != NULL)
	{
		write(2, str, ft_strlen(str));
		str = (char *)va_arg(args, char *);
	}
	va_end(args);
	write(2, "\n", 1);
}
