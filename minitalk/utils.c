/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:49:31 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/08 19:14:33 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*new_node(char c)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}

void	add_back(t_list **lst, t_list *new_node)
{
	t_list	*tmp;

	if (!new_node)
		return ;
	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
	}
}

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		write(1, &(head->c), 1);
		head = head->next;
	}
	write(1, "\n", 1);
}

void	improved_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		ft_printf("Signal transmission failed");
		exit(EXIT_FAILURE);
	}
}
