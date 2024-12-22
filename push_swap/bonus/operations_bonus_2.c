/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:53:55 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 21:57:26 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	ra(t_stack *stack)
{
	t_list	*top;

	top = stack->top;
	if (stack->size < 2)
		return ;
	stack->top = top->next;
	stack->top->prev = NULL;
	top->next = NULL;
	top->prev = stack->bottom;
	stack->bottom->next = top;
	stack->bottom = top;
}

void	rb(t_stack *stack)
{
	t_list	*top;

	top = stack->top;
	if (stack->size < 2)
		return ;
	stack->top = top->next;
	stack->top->prev = NULL;
	top->next = NULL;
	top->prev = stack->bottom;
	stack->bottom->next = top;
	stack->bottom = top;
}

void	rotate(t_stack *stack)
{
	t_list	*top;

	top = stack->top;
	if (stack->size < 2)
		return ;
	stack->top = top->next;
	stack->top->prev = NULL;
	top->next = NULL;
	top->prev = stack->bottom;
	stack->bottom->next = top;
	stack->bottom = top;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
