/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:34:24 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/24 16:25:32 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		kill(data->philos[i].pid, SIGKILL);
	i = -1;
	while (++i < data->nbr_philos)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		sem_unlink(data->philos[i].sem_name);
		sem_close(data->philos[i].philo_sem);
		free(data->philos[i].sem_name);
	}
	sem_unlink(FORK_S);
	sem_unlink(PRINT_S);
	sem_unlink(REPORT_S);
	sem_unlink(FULLPH_S);
	sem_unlink(RUN_S);
	sem_close(data->forks);
	sem_close(data->print_sem);
	sem_close(data->report_sem);
	sem_close(data->full_philos_sem);
	sem_close(data->running);
	free(data->philos);
}

void	wait_all(t_data *data)
{
	int	i;
	int	nbr;

	i = -1;
	nbr = data->nbr_philos;
	while (++i < nbr)
		waitpid(data->philos[i].pid, NULL, 0);
}
