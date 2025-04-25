/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:27:49 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 20:17:36 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_full(void *p_data)
{
	t_data	*data;
	int		i;

	data = (t_data *)p_data;
	i = -1;
	while (++i < data->nbr_philos)
		sem_wait(data->full_philos_sem);
	sem_post(data->report_sem);
	return (NULL);
}

void	*monitor_death(void	*p_philo)
{
	t_philo		*philo;
	long long	current;

	philo = (t_philo *)p_philo;
	while (1337)
	{
		current = get_time();
		if (current - philo->last_meal >= philo->data->time_to_die)
		{
			sem_wait(philo->data->running);
			print_msg(philo->data, philo->id, DIED);
			philo->state = DEAD;
			sem_post(philo->data->report_sem);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
