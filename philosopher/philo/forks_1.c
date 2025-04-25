/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:41:14 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:45:28 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (take_f_fork(philo))
		return (1);
	if (take_s_fork(philo))
	{
		drop_f_fork(philo);
		return (1);
	}
	return (0);
}

int	take_f_fork(t_philo *philo)
{
	if (get_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->first_fork);
	print_msg(philo->data, philo->id, FORK);
	return (0);
}

int	take_s_fork(t_philo *philo)
{
	if (get_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->second_fork);
	print_msg(philo->data, philo->id, FORK);
	return (0);
}
