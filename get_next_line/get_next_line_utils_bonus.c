/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:09:23 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/04 21:09:23 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*tmp;

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

t_list	*ft_lstnew(void *content)
{
	t_list	*ret_value;

	ret_value = (t_list *)malloc(sizeof(t_list));
	if (!ret_value)
	{
		free(content);
		return (NULL);
	}
	ret_value->content = content;
	ret_value->next = NULL;
	return (ret_value);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	t_list	*last;

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

int	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

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

void	update_list(t_list **lst)
{
	t_list	*rest_data;
	t_list	*last_node;
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
