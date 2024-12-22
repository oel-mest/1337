/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:56:51 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 20:57:00 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_rank(t_stack *a)
{
	t_list	*current;
	int		max_rank;

	max_rank = -1;
	current = a->top;
	while (current)
	{
		if (current->rank > max_rank)
			max_rank = current->rank;
		current = current->next;
	}
	return (max_rank);
}

t_list	*get_target(t_stack *a, t_list *node)
{
	t_list	*current;
	t_list	*target;
	int		smallest_big_rank;
	int		max_rank;

	smallest_big_rank = 150000;
	max_rank = find_max_rank(a);
	if (node->rank > max_rank)
	{
		return (find_min(a));
	}
	current = a->top;
	while (current)
	{
		if (current->rank > node->rank)
		{
			if (current->rank < smallest_big_rank)
			{
				target = current;
				smallest_big_rank = current->rank;
			}
		}
		current = current->next;
	}
	return (target);
}

void	assign_targets(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	tmp = b->top;
	while (tmp)
	{
		tmp->target = get_target(a, tmp);
		tmp = tmp->next;
	}
}

t_list	*find_cheapest_node(t_stack *b)
{
	t_list	*current;
	t_list	*cheapest_node;
	int		min_cost;

	current = b->top;
	cheapest_node = current;
	min_cost = current->cost;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

void	calculate_cost(t_stack *a, t_stack *b, t_list *node)
{
	int	cost_a;
	int	cost_b;
	int	target_pos;

	if (node->pos <= b->size / 2)
		cost_b = node->pos - 1;
	else
		cost_b = -(b->size - node->pos + 1);
	target_pos = node->target->pos;
	if (target_pos <= a->size / 2)
		cost_a = target_pos - 1;
	else
		cost_a = -(a->size - target_pos + 1);
	node->cost_a = cost_a;
	node->cost_b = cost_b;
	if (cost_a >= 0 && cost_b >= 0)
		node->cost = ft_max(cost_a, cost_b);
	else if (cost_a < 0 && cost_b < 0)
		node->cost = ft_max(ft_abs(cost_a), ft_abs(cost_b));
	else
		node->cost = ft_abs(cost_a) + ft_abs(cost_b);
}
