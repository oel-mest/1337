/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:51:36 by mel-mora          #+#    #+#             */
/*   Updated: 2024/11/06 08:06:36 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*return_val;

	i = 0;
	return_val = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)ch)
			return_val = ((char *)&str[i]);
		i++;
	}
	if ((char)ch == '\0')
		return ((char *)&str[i]);
	return (return_val);
}
