/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:57:55 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/02 18:08:33 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	div_count;
	int	i;

	div_count = 0;
	i = nb;
	while (i > 0)
	{
		if (nb % i == 0)
			div_count++;
		i--;
	}
	if (div_count != 2)
		return (0);
	else
		return (1);
}
