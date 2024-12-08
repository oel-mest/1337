/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:55:39 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/27 18:44:53 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	ret_value;
	size_t	i;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest < size)
		ret_value = len_dest + len_src;
	else
		ret_value = size + len_src;
	if (size == 0)
		return (ret_value);
	while (src[i] && len_dest + i < size -1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (ret_value);
}
