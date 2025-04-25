/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:04:39 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:50:14 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_data *data)
{
	int	nb_philos;
	int	i;

	i = -1;
	nb_philos = get_nb_philos(data);
	set_start_time(data);
	while (++i < nb_philos)
	{
		if (pthread_create(&data->philos_threads[i],
				NULL, routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monitor_death, NULL, monitor_death, data))
		return (1);
	if (get_max_meals(data) != -1)
	{
		if (pthread_create(&data->monitor_full, NULL, monitor_full, data))
			return (1);
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int	nb_philos;
	int	i;

	i = -1;
	nb_philos = get_nb_philos(data);
	if (pthread_join(data->monitor_death, NULL))
		return (1);
	if (get_max_meals(data) != -1 && pthread_join(data->monitor_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philos_threads[i], NULL))
			return (1);
	}
	return (0);
}

void	clean_data(t_data *data)
{
	int	nbphilos;
	int	i;

	nbphilos = data->nb_philos;
	i = -1;
	while (++i < nbphilos)
	{
		pthread_mutex_destroy(&data->philos[i].nb_meals_mutex);
		pthread_mutex_destroy(&data->philos[i].last_meals_mutex);
		pthread_mutex_destroy(&data->philos[i].state_mutex);
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->starttime_mutex);
	pthread_mutex_destroy(&data->running_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	free(data->philos);
	free(data->forks);
	free(data->philos_threads);
}

int	simulation(int ac, char **av, t_data *data)
{
	int	error;

	error = validate_args(ac, av, data);
	if (error != 0)
		return (error);
	if (init_data(data))
		return (1);
	init_philos(data);
	init_forks(data);
	if (init_threads(data))
		return (2);
	join_threads(data);
	clean_data(data);
	return (0);
}
