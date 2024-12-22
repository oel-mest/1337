/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:01:07 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 19:01:35 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*temp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	free(stack);
}

int	check_duplicate(t_stack *a)
{
	t_list	*current;
	t_list	*cursor;

	if (!a)
		return (0);
	current = a->top;
	while (current)
	{
		cursor = current->next;
		while (cursor)
		{
			if (current->value == cursor->value)
				return (1);
			cursor = cursor->next;
		}
		current = current->next;
	}
	return (0);
}
