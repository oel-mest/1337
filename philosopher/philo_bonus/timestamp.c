/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:10:17 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/21 14:23:27 by oel-mest         ###   ########.fr       */
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

	sem_wait(data->print_sem);
	time = get_time() - data->start_time;
	printf("%llu %d %s\n", time, id, msg);
	sem_post(data->print_sem);
}
