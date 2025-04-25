/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:16:58 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 21:11:52 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_f_fork(t_philo *philo)
{
	if (get_state(philo) != DEAD)
	{
		sem_wait(philo->data->forks);
		print_msg(philo->data, philo->id, FORK);
	}
}

void	pick_s_fork(t_philo *philo)
{
	if (get_state(philo) != DEAD)
	{
		sem_wait(philo->data->forks);
		print_msg(philo->data, philo->id, FORK);
	}
	else
		sem_post(philo->data->forks);
}

void	routine(t_philo *philo)
{
	pthread_t	monitor_th;
	int			first_time;

	first_time = 1;
	set_last_meal(philo, get_time());
	if (pthread_create(&monitor_th, NULL, monitor_death, philo))
		return ((void)printf("pthread create failed\n"));
	while (get_state(philo) != DEAD)
	{
		r_think(philo);
		if (philo->id % 2 == 0 && first_time)
		{
			precise_sleep(5);
			first_time = 0;
		}
		pick_f_fork(philo);
		pick_s_fork(philo);
		set_last_meal(philo, get_time());
		r_eat(philo);
		update_meals_count(philo);
		r_sleep(philo);
	}
	pthread_join(monitor_th, NULL);
}
