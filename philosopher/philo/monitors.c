/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:12:49 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:47:33 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	result;

	result = 0;
	if (get_state(philo) != DEAD && get_time()
		- get_last_meal(philo) >= get_time_to_die(philo->data))
	{
		set_philo_state(DEAD, philo);
		result = 1;
	}
	return (result);
}

void	notify_all_threads(t_data *data)
{
	int	nbr_philos;
	int	i;

	nbr_philos = get_nb_philos(data);
	i = -1;
	while (++i < nbr_philos)
		set_philo_state(DEAD, &data->philos[i]);
}

bool	is_philo_full(t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals(philo) >= get_max_meals(philo->data))
		result = true;
	return (result);
}

void	*monitor_death(void *p_data)
{
	t_data	*data;
	t_philo	*philos;
	int		i;
	int		nb_philos;

	data = (t_data *)p_data;
	philos = data->philos;
	nb_philos = get_nb_philos(data);
	while (get_running(data))
	{
		i = -1;
		while (++i < nb_philos)
		{
			if (check_death(&philos[i]))
			{
				print_msg(data, philos[i].id, DIED);
				notify_all_threads(data);
				set_running(data, false);
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}

void	*monitor_full(void	*p_data)
{
	t_data	*data;
	int		nbr_philos;
	int		i;

	data = (t_data *)p_data;
	nbr_philos = get_nb_philos(data);
	i = -1;
	while (++i < nbr_philos && get_running(data))
	{
		if (is_philo_full(&data->philos[i]) == false)
			i = -1;
	}
	if (get_running(data))
	{
		notify_all_threads(data);
		set_running(data, false);
	}
	return (NULL);
}
