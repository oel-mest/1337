/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:13:08 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:46:40 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (i == 0)
		{
			philos[i].first_fork = &data->forks[i];
			philos[i].second_fork = &data->forks[data->nb_philos - 1];
		}
		else
		{
			philos[i].first_fork = &data->forks[i];
			philos[i].second_fork = &data->forks[i - 1];
		}
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].nb_meals_mutex, NULL);
		pthread_mutex_init(&philos[i].state_mutex, NULL);
		pthread_mutex_init(&philos[i].last_meals_mutex, NULL);
		update_last_meal_time(&philos[i]);
	}
	return (0);
}

int	malloc_all(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (NULL == data->philos)
		return (-1);
	data->forks = malloc(sizeof(t_mutex) * data->nb_philos);
	if (NULL == data->forks)
		return (free(data->philos), -1);
	data->philos_threads = malloc(sizeof(pthread_t) * data->nb_philos);
	if (NULL == data->philos_threads)
		return (free(data->philos), free(data->forks), -1);
	return (0);
}

int	init_data(t_data *data)
{
	data->running = true;
	pthread_mutex_init(&data->starttime_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->running_mutex, NULL);
	if (malloc_all(data))
		return (1);
	return (0);
}
