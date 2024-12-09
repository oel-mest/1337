/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:03:16 by oel-mest          #+#    #+#             */
/*   Updated: 2024/08/29 14:06:01 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	tmp;

	end = size - 1;
	start = 0;
	while (start < end)
	{
		tmp = tab[start];
		tab[start++] = tab[end];
		tab[end--] = tmp;
	}
}
