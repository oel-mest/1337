/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:20:12 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/04 18:20:12 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list2 **lst, t_list2 *node)
{
	t_list2	*tmp;

	if (!node)
		return ;
	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

t_list2	*ft_lstnew(void *content)
{
	t_list2	*ret_value;

	ret_value = (t_list2 *)malloc(sizeof(t_list2));
	if (!ret_value)
	{
		free(content);
		return (NULL);
	}
	ret_value->content = content;
	ret_value->next = NULL;
	return (ret_value);
}

t_list2	*ft_lstlast(t_list2 *lst)
{
	t_list2	*tmp;
	t_list2	*last;

	tmp = lst;
	last = NULL;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

int	ft_lstclear(t_list2 **lst, void (*del)(void *))
{
	t_list2	*tmp;

	if (lst == NULL || *lst == NULL || !del)
		return (1);
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del ((*lst)->content);
		free (*lst);
		*lst = tmp;
	}
	return (1);
}

void	update_list(t_list2 **lst)
{
	t_list2	*rest_data;
	t_list2	*last_node;
	char	*content;
	int		i;
	int		j;

	i = 0;
	j = 0;
	content = malloc (BUFFER_SIZE + 1);
	if (!content && ft_lstclear(lst, free))
		return ;
	last_node = ft_lstlast (*lst);
	if (last_node && content)
	{
		while (last_node->content[i] && last_node->content[i] != '\n')
			i++;
		while (last_node->content[i] && last_node->content[++i])
			content[j++] = last_node->content[i];
		content[j] = '\0';
	}
	rest_data = ft_lstnew(content);
	ft_lstclear(lst, free);
	*lst = rest_data;
	if (rest_data && rest_data->content[0] == 0)
		ft_lstclear(lst, free);
}
