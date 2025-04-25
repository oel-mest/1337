/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:27:51 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 21:13:00 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_nbr_meals(t_philo *philo)
{
	sem_wait(philo->philo_sem);
	philo->nbr_meals++;
	sem_post(philo->philo_sem);
}

void	set_last_meal(t_philo *philo, long long value)
{
	sem_wait(philo->philo_sem);
	philo->last_meal = value;
	sem_post(philo->philo_sem);
}

void	set_state(t_philo *philo, t_status value)
{
	sem_wait(philo->philo_sem);
	philo->state = value;
	sem_post(philo->philo_sem);
}

void	update_meals_count(t_philo *philo)
{
	int	nbr_meals;

	update_nbr_meals(philo);
	nbr_meals = get_nbr_meals(philo);
	if (nbr_meals >= philo->data->max_eats && get_state(philo) != FULL)
	{
		set_state(philo, FULL);
		sem_post(philo->data->full_philos_sem);
	}
}
