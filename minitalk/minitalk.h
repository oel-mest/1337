/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:35:40 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/08 20:24:59 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list{
	char			c;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *str, ...);
t_list	*new_node(char c);
void	add_back(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst);
void	print_list(t_list *head);
void	improved_kill(pid_t pid, int signum);
int		ft_atoi(const char *str);
void	send_char(char c, pid_t server_pid);
void	send_string(char *str, pid_t server_pid);
void	*ft_memset(void *b, int c, size_t len);

#endif