/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:27:52 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/11 15:25:31 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i ++;
	}
	return (0);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	i;
	char	*old_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	old_ptr = (char *)ptr;
	i = 0;
	while (i < size && old_ptr[i])
	{
		((char *)new_ptr)[i] = old_ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

char	**ft_realloc_ptr_array(char **ptr, size_t old_size, size_t new_size)
{
	char	**new_ptr;
	size_t	i;

	new_ptr = malloc(sizeof(char *) * new_size);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
