/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:42:06 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 16:42:36 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	validate_argv(int argc, char **argv)
{
	char	**numbers;
	int		i;
	long	num;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		i = 0;
		while (numbers[i])
		{
			num = ft_atol(numbers[i]);
			if (!is_valid_number(numbers[i]) || num > INT_MAX || num < INT_MIN)
			{
				ft_putendl_fd("Error", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	else if (argc > 2)
	{
		validate_multi(argc, argv);
	}
}

void	validate_multi(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (!is_valid_number(argv[i]) || num > INT_MAX || num < INT_MIN)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
