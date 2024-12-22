/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:04:13 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 18:25:22 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				rank;
	int				pos;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target;
	int				cost_a;
	int				cost_b;
	int				cost;
}	t_list;

typedef struct s_stack
{
	int		size;
	t_list	*top;
	t_list	*bottom;
}	t_stack;
//operations
void	pa(t_stack *source, t_stack *destination);
void	pb(t_stack *source, t_stack *destination);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	swap(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rotate(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrotate(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
//algorithm fnctions
void	sort_three(t_stack *a);
t_list	*get_target(t_stack *a, t_list *node);
void	finish_sorting(t_stack *s, t_list *node);
void	update_pos(t_stack *s);
void	assign_rank(t_stack *s, int	*ptr);
int		get_rank(int *ptr, int value, int size);
int		find_max_rank(t_stack *a);
void	calculate_cost(t_stack *a, t_stack *b, t_list *node);
void	assign_cost(t_stack *a, t_stack *b);
void	assign_targets(t_stack *a, t_stack *b);
t_list	*find_cheapest_node(t_stack *b);
void	place_node(t_stack *a, t_stack *b, t_list *node);
void	move_all(t_stack *a, t_stack *b);
void	move_chunks(t_stack *a, t_stack *b, int chunk_size);
void	execute_rr(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	execute_rrr(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	execute_a(t_stack *a, int *cost_a);
void	execute_b(t_stack *b, int *cost_b);
// helpers functions
void	sort_table(int *ptr, int size);
int		is_sorted(t_stack *stack);
void	ft_putendl(char *str);
void	push(t_stack *stack, int value);
t_stack	*init_stack(void);
t_list	*new_node(int value);
t_list	*find_max(t_stack *s);
t_list	*find_min(t_stack *s);
t_stack	*init_stack_from_argv(int argc, char **argv);
void	fetch_single_numbers(t_stack *a, int argc, char **argv);
int		*create_table_from_stack(t_stack *stack);
int		ft_abs(int a);
int		ft_max(int a, int b);
char	**ft_split(char *str, char c);
int		ft_atoi(char *str);
long	ft_atol(char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_putendl_fd(char *s, int fd);
// control functions
void	free_stack(t_stack *stack);
void	check_stack_integrity(t_stack *stack);
int		check_duplicate(t_stack *a);
void	validate_argv(int argc, char **argv);
void	validate_multi(int argc, char **argv);
#endif