/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:19:55 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 20:21:58 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	r_think(t_philo *philo)
{
	if (get_state(philo) != DEAD)
		print_msg(philo->data, philo->id, THINKING);
}

void	r_eat(t_philo *philo)
{
	if (get_state(philo) != DEAD)
	{
		print_msg(philo->data, philo->id, EATING);
		precise_sleep(philo->data->time_to_eat);
	}
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	r_sleep(t_philo *philo)
{
	if (get_state(philo) != DEAD)
	{
		print_msg(philo->data, philo->id, SLEEPING);
		precise_sleep(philo->data->time_to_sleep);
	}
}
