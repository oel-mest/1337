/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:01 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/24 17:25:33 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
