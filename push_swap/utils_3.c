/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:57:48 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 22:03:05 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	t_list	*max;

	max = find_max(a);
	if (a->top->value == max->value)
		ra(a);
	else if (a->top->next->value == max->value)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	move_all(t_stack *a, t_stack *b)
{
	while (!is_sorted(a) && a->size > 3)
	{
		pb(a, b);
	}
}

void	assign_cost(t_stack *a, t_stack *b)
{
	t_list	*current;

	current = b->top;
	while (current)
	{
		calculate_cost(a, b, current);
		current = current->next;
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && i < len_src)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}
