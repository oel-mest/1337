/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:17:10 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 22:01:46 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_table_from_stack(t_stack *stack)
{
	int		*table;
	t_list	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (NULL);
	table = malloc(stack->size * sizeof(int));
	if (!table)
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
	current = stack->top;
	i = 0;
	while (current)
	{
		table[i] = current->value;
		current = current->next;
		i++;
	}
	return (table);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
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
