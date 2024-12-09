/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:35:57 by oel-mest          #+#    #+#             */
/*   Updated: 2024/08/31 12:48:34 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!dest || !src)
		return (dest);
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len++] = src[i++];
	}
	dest[len] = '\0';
	return (dest);
}
