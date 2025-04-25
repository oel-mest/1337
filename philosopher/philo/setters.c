/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:08:47 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:49:22 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start_time(t_data *data)
{
	pthread_mutex_lock(&data->starttime_mutex);
	data->start_time = get_time();
	pthread_mutex_unlock(&data->starttime_mutex);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meals_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meals_mutex);
}

void	update_nb_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->nb_meals_mutex);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->nb_meals_mutex);
}

void	set_philo_state(t_state status, t_philo *philo)
{
	pthread_mutex_lock(&philo->state_mutex);
	philo->state = status;
	pthread_mutex_unlock(&philo->state_mutex);
}

void	set_running(t_data *data, bool newval)
{
	pthread_mutex_lock(&data->running_mutex);
	data->running = newval;
	pthread_mutex_unlock(&data->running_mutex);
}
