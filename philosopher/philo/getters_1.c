/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:45:07 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:37:11 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_running(t_data *data)
{
	bool	result;

	pthread_mutex_lock(&data->running_mutex);
	result = data->running;
	pthread_mutex_unlock(&data->running_mutex);
	return (result);
}

int	get_nb_philos(t_data *data)
{
	return (data->nb_philos);
}

long long	get_start_time(t_data *data)
{
	long long	result;

	pthread_mutex_lock(&data->starttime_mutex);
	result = data->start_time;
	pthread_mutex_unlock(&data->starttime_mutex);
	return (result);
}

long long	get_time_to_eat(t_data *data)
{
	return (data->time_to_eat);
}

long long	get_time_to_sleep(t_data *data)
{
	return (data->time_to_sleep);
}
