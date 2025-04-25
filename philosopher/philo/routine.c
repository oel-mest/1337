/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:11:27 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:49:08 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_one_philo(t_philo *philo)
{
	print_msg(philo->data, philo->id, THINK);
	take_f_fork(philo);
	precise_sleep(get_time_to_die(philo->data));
	return (1);
}

int	r_eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	print_msg(philo->data, philo->id, EAT);
	update_last_meal_time(philo);
	precise_sleep(get_time_to_eat(philo->data));
	update_nb_meals(philo);
	drop_forks(philo);
	return (0);
}

int	r_sleep(t_philo *philo)
{
	if (get_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, SLEEP);
	precise_sleep(get_time_to_sleep(philo->data));
	return (0);
}

int	r_think(t_philo *philo)
{
	if (get_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, THINK);
	return (0);
}

void	*routine(void *p_philo)
{
	t_philo	*philo;
	int		first_time;

	philo = (t_philo *)p_philo;
	update_last_meal_time(philo);
	first_time = 1;
	while (get_state(philo) != DEAD)
	{
		if (get_nb_philos(philo->data) == 1)
			return (handle_one_philo(philo), NULL);
		if (r_think(philo))
			break ;
		if (first_time && philo->id % 2 == 0)
			precise_sleep(get_time_to_eat(philo->data) - 10);
		if (first_time && philo->id % 2
			&& philo->id == get_nb_philos(philo->data))
			precise_sleep(get_time_to_eat(philo->data)
				+ get_time_to_eat(philo->data) / 2);
		first_time = 0;
		if (r_eat(philo))
			break ;
		if (r_sleep(philo))
			break ;
	}
	return (NULL);
}
