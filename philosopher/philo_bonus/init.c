/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:26 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 19:37:55 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_sem(sem_t **semaphore, char *name, int value)
{
	sem_unlink(name);
	*semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (*semaphore == SEM_FAILED)
	{
		printf("sem_open failed \n");
		exit(EXIT_FAILURE);
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		data->philos[i].data = data;
		data->philos[i].state = IDLE;
		data->philos[i].id = i + 1;
		data->philos[i].nbr_meals = 0;
		data->philos[i].sem_name = gen_sem_name(data->philos[i].id);
		create_sem(&data->philos[i].philo_sem, data->philos[i].sem_name, 1);
	}
	i = -1;
	data->start_time = get_time();
	while (++i < data->nbr_philos)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid < 0)
		{
			printf("Fork error - philo id [%d]\n", data->philos[i].id);
			exit(EXIT_FAILURE);
		}
		else if (data->philos[i].pid == 0)
			routine(&data->philos[i]);
	}
}

void	init_data(t_data *data)
{
	create_sem(&data->forks, FORK_S, data->nbr_philos);
	create_sem(&data->report_sem, REPORT_S, 0);
	create_sem(&data->full_philos_sem, FULLPH_S, 0);
	create_sem(&data->print_sem, PRINT_S, 1);
	create_sem(&data->running, RUN_S, 1);
	data->philos = malloc(sizeof(t_philo) * data->nbr_philos);
	if (NULL == data->philos)
	{
		printf("Malloc error\n");
		exit(EXIT_FAILURE);
	}
	init_philo(data);
}
