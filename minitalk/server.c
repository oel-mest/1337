/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:47:52 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/08 20:10:43 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*g_head = NULL;

void	my_handler(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	sender = 0;

	(void)context;
	if (info->si_pid)
		sender = info->si_pid;
	if (signal == SIGUSR1)
		c |= (0b10000000 >> bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == '\0')
		{
			add_back(&g_head, new_node(c));
			print_list(g_head);
			ft_lstclear(&g_head);
			improved_kill(sender, SIGUSR2);
		}
		else
			add_back(&g_head, new_node(c));
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = my_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("sigaction failed");
		exit(EXIT_FAILURE);
	}
	ft_printf("✅ Server started\n🧠 PID : %d\n", getpid());
	ft_printf("⌛ Listening ...\n");
	while (42)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
