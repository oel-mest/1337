/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:55:40 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/27 17:34:37 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_list;
	t_list	*new_tmp;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	tmp = lst;
	while (tmp != NULL)
	{
		new_content = f(tmp->content);
		new_tmp = ft_lstnew(new_content);
		if (!new_tmp)
		{
			del (new_content);
			ft_lstclear (&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_tmp);
		tmp = tmp->next;
	}
	return (new_list);
}
