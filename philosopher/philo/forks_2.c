/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:39:40 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:44:12 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	drop_f_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
}

void	drop_s_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->second_fork);
}
