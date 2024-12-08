/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:44:01 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/24 17:26:18 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret_value;

	ret_value = (t_list *)malloc(sizeof(t_list));
	if (!ret_value)
		return (NULL);
	ret_value->content = content;
	ret_value->next = NULL;
	return (ret_value);
}
