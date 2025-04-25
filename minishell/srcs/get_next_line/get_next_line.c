/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:54 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/04 18:19:54 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_endlpos(t_list2 **lst)
{
	t_list2	*tmp;
	ssize_t	pos;
	ssize_t	j;

	tmp = *lst;
	pos = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j] != '\0')
		{
			if (tmp->content[j] == '\n')
				return (pos);
			j++;
			pos++;
		}
		tmp = tmp->next;
	}
	return (pos - 1);
}

ssize_t	check_endl(t_list2 **lst)
{
	t_list2	*tmp;
	ssize_t	pos;
	ssize_t	j;

	tmp = *lst;
	pos = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j] != '\0')
		{
			if (tmp->content[j] == '\n')
				return (1);
			j++;
			pos++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	read_until_line(t_list2 **lst, int fd)
{
	char	*buffer;
	ssize_t	newline_exist;
	int		char_read;
	t_list2	*new_node;

	newline_exist = check_endl (lst);
	while (newline_exist == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return (char_read);
		}
		buffer[char_read] = '\0';
		new_node = ft_lstnew(buffer);
		if (!new_node)
			return (-1);
		ft_lstadd_back(lst, new_node);
		newline_exist = check_endl(lst);
	}
	return (0);
}

char	*fetch_oneline(t_list2 *lst, char *line)
{
	t_list2	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j] != '\0')
		{
			line[i] = tmp->content[j];
			if (line[i] == '\n')
			{
				line[i + 1] = '\0';
				return (line);
			}
			j++;
			i++;
		}
		tmp = tmp->next;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list2	*head;
	char			*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_until_line(&head, fd) == -1)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	if (!head)
		return (NULL);
	one_line = malloc(get_endlpos(&head) + 2);
	if (!one_line)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	fetch_oneline(head, one_line);
	update_list(&head);
	return (one_line);
}
