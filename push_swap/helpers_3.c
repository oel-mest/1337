/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:25:38 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 21:54:50 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_convert(char *str, int i)
{
	int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	rez;
	int	sign;

	sign = 1;
	i = 0;
	while (ft_isspace (str[i]))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	rez = ft_convert (str, i);
	return (rez * sign);
}

t_stack	*init_stack_from_argv(int argc, char **argv)
{
	t_stack	*a;
	char	**numbers;
	int		i;

	a = init_stack();
	if (argc == 2)
	{
		i = 0;
		numbers = ft_split(argv[1], ' ');
		while (numbers[i] != NULL)
			i++;
		while (--i >= 0)
		{
			push(a, ft_atoi(numbers[i]));
			free(numbers[i]);
		}
		free(numbers);
	}
	else if (argc > 2)
		fetch_single_numbers(a, argc, argv);
	return (a);
}

void	fetch_single_numbers(t_stack *a, int argc, char **argv)
{
	int	i;

	i = argc;
	while (--i > 0)
		push(a, ft_atoi(argv[i]));
}
