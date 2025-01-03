/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:35:40 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/23 15:45:12 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putendl_fd(char *s, int fd);
void	improved_kill(pid_t pid, int signum);
int		ft_atoi(const char *str);
void	send_char(char c, pid_t server_pid);
void	send_string(char *str, pid_t server_pid);
void	*ft_memset(void *b, int c, size_t len);
int		ftput_endl(char **g_str, int *taille);
void	ft_realloc(char **str, int taille, int old_taille);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif