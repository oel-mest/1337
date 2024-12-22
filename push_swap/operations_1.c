/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:52:41 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/19 20:53:39 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *source, t_stack *destination)
{
	t_list	*node_to_move;

	node_to_move = source->top;
	if (source->size == 0)
	{
		ft_putendl("Error");
		return ;
	}
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
	update_pos(source);
	update_pos(destination);
	ft_putendl("pa");
}

void	pb(t_stack *source, t_stack *destination)
{
	t_list	*node_to_move;

	node_to_move = source->top;
	if (source->size == 0)
	{
		ft_putendl("Error");
		return ;
	}
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
	update_pos(source);
	update_pos(destination);
	ft_putendl("pb");
}

void	sa(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	first = stack->top;
	second = first->next;
	if (stack->size < 2)
		return ;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	update_pos(stack);
	ft_putendl("sa");
}

void	sb(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	first = stack->top;
	second = first->next;
	if (stack->size < 2)
		return ;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	update_pos(stack);
	ft_putendl("sb");
}

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	first = stack->top;
	second = first->next;
	if (stack->size < 2)
		return ;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	update_pos(stack);
}
