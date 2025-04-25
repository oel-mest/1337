/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:22:24 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 19:27:44 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_nbr_meals(t_philo *philo)
{
	int	result;

	sem_wait(philo->philo_sem);
	result = philo->nbr_meals;
	sem_post(philo->philo_sem);
	return (result);
}

t_status	get_state(t_philo *philo)
{
	t_status	result;

	sem_wait(philo->philo_sem);
	result = philo->state;
	sem_post(philo->philo_sem);
	return (result);
}

long long	get_last_meal(t_philo *philo)
{
	long long	result;

	sem_wait(philo->philo_sem);
	result = philo->last_meal;
	sem_post(philo->philo_sem);
	return (result);
}
