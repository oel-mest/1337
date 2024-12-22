/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:54:49 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 20:55:04 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_list	*bottom;

	bottom = stack->bottom;
	if (stack->size <= 1)
		return ;
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	bottom->prev = NULL;
	bottom->next = stack->top;
	stack->top->prev = bottom;
	stack->top = bottom;
	update_pos(stack);
	ft_putendl("rra");
}

void	rrb(t_stack *stack)
{
	t_list	*bottom;

	bottom = stack->bottom;
	if (stack->size <= 1)
		return ;
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	bottom->prev = NULL;
	bottom->next = stack->top;
	stack->top->prev = bottom;
	stack->top = bottom;
	update_pos(stack);
	ft_putendl("rrb");
}

void	rrotate(t_stack *stack)
{
	t_list	*bottom;

	bottom = stack->bottom;
	if (stack->size <= 1)
		return ;
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	bottom->prev = NULL;
	bottom->next = stack->top;
	stack->top->prev = bottom;
	stack->top = bottom;
	update_pos(stack);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
	ft_putendl("rrr");
}
