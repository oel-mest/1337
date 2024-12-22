/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:16:28 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 22:30:43 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free(b);
}

void	ft_failure(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free_stacks (a, b);
	exit(EXIT_FAILURE);
}

void	execute_operations(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa (a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb (b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss (a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa (b, a);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb (a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra (a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb (b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr (a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra (a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb (b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr (a, b);
	else
		ft_failure (a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	validate_argv(argc, argv);
	a = init_stack_from_argv(argc, argv);
	b = init_stack();
	if (check_duplicate(a))
		ft_failure(a, b);
	command = get_next_line (STDIN_FILENO);
	while (command)
	{
		execute_operations (a, b, command);
		command = get_next_line (STDIN_FILENO);
	}
	if (is_sorted(a) && b->size == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_stacks(a, b);
	return (0);
}
