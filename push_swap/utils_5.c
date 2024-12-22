/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:23:28 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 18:25:44 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_chunk(int chunk_min, int chunk_max, t_list *current)
{
	if (current->rank >= chunk_min && current->rank < chunk_max)
		return (1);
	return (0);
}

int	count_chunks(t_stack *a, int min, int max)
{
	int		count;
	t_list	*current;

	current = a->top;
	count = 0;
	while (current)
	{
		if (in_chunk(min, max, current))
			count++;
		current = current->next;
	}
	return (count);
}

void	move_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int		chunk_min;
	int		chunk_max;
	int		count;
	int		starter_size;

	chunk_min = 0;
	chunk_max = chunk_size;
	starter_size = a->size;
	while (chunk_min < starter_size && a->size > 3)
	{
		count = count_chunks(a, chunk_min, chunk_max);
		while (count > 0 && a->size > 3)
		{
			if (in_chunk(chunk_min, chunk_max, a->top))
			{
				pb(a, b);
				count--;
			}
			else
				ra(a);
		}
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
}
