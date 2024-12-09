/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:54:43 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/09 20:41:13 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, pid_t server_pid)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			improved_kill(server_pid, SIGUSR1);
		else
			improved_kill(server_pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

void	send_string(char *str, pid_t server_pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], server_pid);
		i++;
	}
	send_char('\0', server_pid);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (b);
}
