/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:58:15 by oel-mest          #+#    #+#             */
/*   Updated: 2024/08/31 13:15:36 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len_d;
	unsigned int	i;

	len_d = 0;
	i = 0;
	if (!dest || !src)
		return (dest);
	while (dest[len_d])
		len_d++;
	while (src[i] && i < nb)
	{
		dest[len_d++] = src[i++];
	}
	dest[len_d] = '\0';
	return (dest);
}
