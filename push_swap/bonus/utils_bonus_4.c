/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:37:14 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 20:55:28 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	push(t_stack *stack, int value)
{
	t_list	*node;

	node = new_node(value);
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}
