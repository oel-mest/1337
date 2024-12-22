/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:53:55 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 20:54:22 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl("ss");
}

void	ra(t_stack *stack)
{
	t_list	*top;

	top = stack->top;
	if (stack->size <= 1)
		return ;
	stack->top = top->next;
	stack->top->prev = NULL;
	top->next = NULL;
	top->prev = stack->bottom;
	stack->bottom->next = top;
	stack->bottom = top;
	update_pos(stack);
	ft_putendl("ra");
}

void	rb(t_stack *stack)
{
	t_list	*top;

	top = stack->top;
	if (stack->size <= 1)
		return ;
	stack->top = top->next;
	stack->top->prev = NULL;
	top->next = NULL;
	top->prev = stack->bottom;
	stack->bottom->next = top;
	stack->bottom = top;
	update_pos(stack);
	ft_putendl("rb");
}

void	rotate(t_stack *stack)
{
	t_list	*top;

	top = stack->top;
	if (stack->size <= 1)
		return ;
	stack->top = top->next;
	stack->top->prev = NULL;
	top->next = NULL;
	top->prev = stack->bottom;
	stack->bottom->next = top;
	stack->bottom = top;
	update_pos(stack);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl("rr");
}
