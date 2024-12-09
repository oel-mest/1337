/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:04:10 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/02 13:16:49 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact_val;

	fact_val = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1 && nb >= 0)
		return (fact_val);
	else
	{
		while (nb > 1)
		{
			fact_val *= nb;
			nb--;
		}
	}
	return (fact_val);
}
