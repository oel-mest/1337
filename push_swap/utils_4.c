/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:40:59 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 21:15:32 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_node(t_stack *a, t_stack *b, t_list *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	execute_rr(a, b, &cost_a, &cost_b);
	execute_rrr(a, b, &cost_a, &cost_b);
	execute_a(a, &cost_a);
	execute_b(b, &cost_b);
	pa(b, a);
}

void	execute_rr(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	execute_rrr(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_a(t_stack *a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

void	execute_b(t_stack *b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}
