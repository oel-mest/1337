/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:37:13 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:37:20 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_to_die(t_data *data)
{
	return (data->time_to_die);
}

int	get_max_meals(t_data *data)
{
	return (data->nb_meals);
}
///// getters philo

t_state	get_state(t_philo *philo)
{
	t_state	result;

	pthread_mutex_lock(&philo->state_mutex);
	result = philo->state;
	pthread_mutex_unlock(&philo->state_mutex);
	return (result);
}

int	get_nb_meals(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->nb_meals_mutex);
	result = philo->nb_meals;
	pthread_mutex_unlock(&philo->nb_meals_mutex);
	return (result);
}

long long	get_last_meal(t_philo *philo)
{
	long long	result;

	pthread_mutex_lock(&philo->last_meals_mutex);
	result = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meals_mutex);
	return (result);
}
