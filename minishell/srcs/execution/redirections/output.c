/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:15:14 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:13 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	open_last_output_file(t_output *output_list, int append)
{
	int			fd;
	t_output	*current;
	int			flags;

	fd = -1;
	current = output_list;
	while (current)
	{
		flags = O_WRONLY | O_CREAT | O_CLOEXEC;
		if (append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		if (fd != -1)
			close(fd);
		hundle_awk2(&current->file);
		current->file = remove_first_layer_quotes(current->file);
		fd = open(current->file, flags, 0644);
		if (fd < 0)
			return (print_error(current->file,
					": No such file or directory", NULL), -1);
		current = current->next;
	}
	return (fd);
}

int	redirect_output(t_output *output_list, int append)
{
	int	fd;

	fd = open_last_output_file(output_list, append);
	if (fd < 0)
		return (1);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		print_error("dup2 output file", NULL);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
