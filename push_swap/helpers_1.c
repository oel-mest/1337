/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:16:30 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 18:59:15 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

t_list	*find_min(t_stack *s)
{
	int		lowest_rank;
	t_list	*current;
	t_list	*target;

	target = NULL;
	current = s->top;
	lowest_rank = 150000;
	while (current)
	{
		if (current->rank < lowest_rank)
		{
			target = current;
			lowest_rank = target->rank;
		}
		current = current->next;
	}
	return (target);
}

t_list	*find_max(t_stack *s)
{
	t_list	*max;
	t_list	*current;

	if (s->size == 0)
		return (NULL);
	current = s->top;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_list	*new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->target = NULL;
	node->rank = 0;
	node->cost = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->pos = 0;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}
