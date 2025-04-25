/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:22:18 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:47:51 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validate_int(char *arg, int *value, int *error)
{
	char	*ptr;

	ptr = arg;
	if (*ptr == '+' || *ptr == '-' )
		ptr++;
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
		{
			*error = -1;
			return ;
		}
		ptr++;
	}
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < 0)
	{
		*error = -1;
		return ;
	}
	*value = (int)ft_atol(arg);
}

static void	validate_long(char *arg, long long *value, int *error)
{
	char	*ptr;

	ptr = arg;
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
		{
			*error = -1;
			return ;
		}
		ptr++;
	}
	if (ft_atol(arg) < 0)
	{
		*error = -1;
		return ;
	}
	*value = (long long)ft_atol(arg);
}

int	validate_args(int ac, char **av, t_data *data)
{
	int	error;

	error = 0;
	validate_int (av[1], &data->nb_philos, &error);
	validate_long (av[2], &data->time_to_die, &error);
	validate_long (av[3], &data->time_to_eat, &error);
	validate_long (av[4], &data->time_to_sleep, &error);
	if (ac == 5)
		data->nb_meals = -1;
	else
		validate_int(av[5], &data->nb_meals, &error);
	if (data->nb_philos == 0)
		error = 42;
	return (error);
}
