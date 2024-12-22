/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:49:43 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/20 20:57:38 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	int		size;
	t_list	*top;
	t_list	*bottom;
}	t_stack;

void	ft_putendl_fd(char *s, int fd);
int		ft_isspace(char c);
long	ft_convertl(char *str, int i);
long	ft_atol(char *str);
int		ft_count_words(char *str, char c);
void	*free_split(char **strs, int count);
int		add_string(char **strs, char *str, int start, int len);
char	**ft_split(char *str, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_convert(char *str, int i);
int		ft_atoi(char *str);
t_stack	*init_stack_from_argv(int argc, char **argv);
void	fetch_single_numbers(t_stack *a, int argc, char **argv);
size_t	ft_strlen(const char *str);
t_list	*new_node(int value);
t_stack	*init_stack(void);
int		is_sorted(t_stack *stack);
void	free_stacks(t_stack *a, t_stack *b);
void	ft_failure(t_stack *a, t_stack *b);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);
void	execute_operations(t_stack *a, t_stack *b, char *op);
void	push(t_stack *stack, int value);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

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

void	free_stack(t_stack *stack);
int		check_duplicate(t_stack *a);
void	validate_argv(int argc, char **argv);
void	validate_multi(int argc, char **argv);
#endif