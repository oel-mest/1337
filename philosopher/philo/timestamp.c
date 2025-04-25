/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:10:07 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:39:00 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	precise_sleep(long long sleep_time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

void	print_msg(t_data *data, int id, char *msg)
{
	long long	time;

	pthread_mutex_lock(&data->print_mutex);
	time = get_time() - get_start_time(data);
	if (get_running(data))
		printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}
