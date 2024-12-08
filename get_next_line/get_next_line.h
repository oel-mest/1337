/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:20:15 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/04 18:20:15 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	char			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *node);
t_list	*ft_lstnew(void *content);
char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstclear(t_list **lst, void (*del)(void *));
void	update_list(t_list **lst);
char	*fetch_oneline(t_list *lst, char *line);
int		read_until_line(t_list **lst, int fd);
ssize_t	check_endl(t_list **lst);
size_t	get_endlpos(t_list **lst);

#endif