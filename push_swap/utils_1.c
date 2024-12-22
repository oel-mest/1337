/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:56:08 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 20:56:25 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_table(int *ptr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ptr[i] > ptr[j])
			{
				tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_rank(int *ptr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] == value)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	assign_rank(t_stack *s, int *ptr)
{
	t_list	*current;

	current = s->top;
	while (current)
	{
		current->rank = get_rank(ptr, current->value, s->size);
		current = current->next;
	}
}

void	update_pos(t_stack *s)
{
	t_list	*current;
	int		pos;

	current = s->top;
	pos = 1;
	while (current != NULL)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

void	finish_sorting(t_stack *s, t_list *node)
{
	while (s->bottom != node)
	{
		if (node->pos < s->size / 2)
			ra(s);
		else
			rra(s);
	}
}
