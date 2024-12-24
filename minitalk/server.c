/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:47:52 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/23 15:48:01 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str = NULL;

void	my_handler(int signal, siginfo_t *info
	, void *context __attribute__((unused)))
{
	static char		c = 0;
	static int		bit = 0;
	static int		i = 0;
	static int		current_taille = 0;

	if (signal == SIGUSR1)
		c |= (0b10000000 >> bit);
	if (++bit == CHAR_BIT)
	{
		bit = 0;
		if (i >= current_taille)
		{
			current_taille += 100;
			ft_realloc(&g_str, current_taille, i);
		}
		if (c == '\0')
		{
			g_str[i++] = c;
			i = ftput_endl(&g_str, &current_taille);
			improved_kill(info->si_pid, SIGUSR2);
		}
		else
			g_str[i++] = c;
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
		ft_putendl_fd ("❌ Sigaction failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_printf("✅ Server started\n🧠 PID : %d\n", getpid());
	ft_printf("⌛ Listening ...\n");
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
