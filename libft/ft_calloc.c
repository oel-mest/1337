/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:42:35 by oel-mest          #+#    #+#             */
/*   Updated: 2024/10/28 13:58:39 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (count != 0 && size > 18446744073709551615U / count)
		return ((void *) NULL);
	total = count * size;
	ptr = malloc (total);
	if (ptr == NULL)
	{
		return ((void *) NULL);
	}
	ft_memset (ptr, 0, total);
	return (ptr);
}
