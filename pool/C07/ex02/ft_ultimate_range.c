/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:13:02 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/04 17:17:42 by oel-mest         ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range (min, max);
	if (*range == NULL)
		return (-1);
	else
		return (max - min);
}
