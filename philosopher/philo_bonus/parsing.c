/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:10:28 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 20:17:48 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validate_int(char *arg, int *value)
{
	char	*ptr;

	ptr = arg;
	if (*ptr == '+' || *ptr == '-' )
		ptr++;
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
		{
			printf("Invalid arguments\n");
			exit(EXIT_FAILURE);
		}
		ptr++;
	}
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < 0)
	{
		printf("Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	*value = (int)ft_atol(arg);
}

static void	validate_long(char *arg, long long *value)
{
	char	*ptr;

	ptr = arg;
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
		{
			printf("Invalid arguments\n");
			exit(EXIT_FAILURE);
		}
		ptr++;
	}
	if (ft_atol(arg) < 0)
	{
		printf("Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	*value = ft_atol(arg);
}

void	validate_args(int ac, char **av, t_data *data)
{
	validate_int (av[1], &data->nbr_philos);
	validate_long (av[2], &data->time_to_die);
	validate_long (av[3], &data->time_to_eat);
	validate_long (av[4], &data->time_to_sleep);
	if (ac == 5)
		data->max_eats = -1;
	else
		validate_int(av[5], &data->max_eats);
}
