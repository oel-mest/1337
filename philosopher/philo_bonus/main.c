/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:11:32 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/25 18:37:03 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_deaths(t_data *data)
{
	int	i;

	i = -1;
	sem_wait(data->report_sem);
	while (++i < data->nbr_philos)
		sem_post(data->full_philos_sem);
	clean_data(data);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;

	if (ac == 5 || ac == 6)
	{
		validate_args(ac, av, &data);
		if (data.nbr_philos == 0 || data.max_eats == 0)
			return (0);
		init_data(&data);
		if (data.max_eats != -1)
		{
			if (pthread_create(&monitor, NULL, monitor_full, &data) != 0)
			{
				printf("creating monitor thread failed!");
				exit(EXIT_FAILURE);
			}
		}
		check_deaths(&data);
	}
	else
		return (printf("Invalid number of arguments\n"), 1);
	wait_all(&data);
	return (0);
}
