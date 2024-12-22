/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:52:41 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 22:04:00 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack *source, t_stack *destination)
{
	t_list	*node_to_move;

	node_to_move = source->top;
	if (source->size == 0)
		return ;
	source->top = node_to_move->next;
	if (source->top)
		source->top->prev = NULL;
	else
		source->bottom = NULL;
	source->size--;
	node_to_move->next = destination->top;
	if (destination->top)
		destination->top->prev = node_to_move;
	else
		destination->bottom = node_to_move;
	node_to_move->prev = NULL;
	destination->top = node_to_move;
	destination->size++;
}

void	pb(t_stack *source, t_stack *destination)
{
	t_list	*node_to_move;

	node_to_move = source->top;
	if (source->size == 0)
		return ;
	source->top = node_to_move->next;
	if (source->top)
		source->top->prev = NULL;
	else
		source->bottom = NULL;
	source->size--;
	node_to_move->next = destination->top;
	if (destination->top)
		destination->top->prev = node_to_move;
	else
		destination->bottom = node_to_move;
	node_to_move->prev = NULL;
	destination->top = node_to_move;
	destination->size++;
}

void	sa(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sb(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}
