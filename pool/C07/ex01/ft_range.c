/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:55 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/04 15:11:52 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	taille;
	int	i;

	taille = max - min;
	if (taille <= 0)
		return (NULL);
	tab = (int *)malloc(taille * 4);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < taille)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
