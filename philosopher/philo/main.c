/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:13:57 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/25 18:24:05 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	if (ac < 5 || ac > 6)
		printf("Invalid number of arguments\n");
	else
	{
		error = simulation(ac, av, &data);
		if (error == -1)
			printf("Invalid arguments\n");
		else if (error == 1)
			printf("Malloc failed\n");
		else if (error == 2)
		{
			printf("Pthreade create failed\n");
			clean_data(&data);
		}
		else if (error == 42)
			return (0);
		else
			return (error);
	}
	return (1);
}
