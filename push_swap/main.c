/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:40:25 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/22 18:22:30 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_failure(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free_stack(a);
	free(b);
	exit(EXIT_FAILURE);
}


void	check_leaks()
{
	system("leaks push_swap");
}
void	sort_algo(t_stack *a, t_stack *b)
{
	int	*tab;

	tab = create_table_from_stack(a);
	if (!tab)
		ft_failure(a, b);
	sort_table(tab, a->size);
	assign_rank(a, tab);
	update_pos(a);
	if (a->size <= 110)
		move_all(a, b);
	else
		move_chunks (a, b, 100);
	sort_three(a);
	while (b->size > 0)
	{
		assign_targets(a, b);
		assign_cost(a, b);
		place_node(a, b, find_cheapest_node(b));
	}
	finish_sorting(a, find_max(a));
	free(tab);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	//atexit(check_leaks);
	validate_argv(argc, argv);
	a = init_stack_from_argv(argc, argv);
	b = init_stack();
	if (check_duplicate(a))
		ft_failure(a, b);
	if (a->size == 3)
		sort_three(a);
	else if (a->size < 3)
	{
		if (a->size == 2)
			if (a->top->value > a->bottom->value)
				sa(a);
	}
	else
		sort_algo(a, b);
	free_stack(a);
	free(b);
	return (0);
}
