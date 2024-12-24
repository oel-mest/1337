/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:44:08 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/23 16:22:20 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_handler(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_putendl_fd ("✅ Message sent successfully!", STDOUT_FILENO);
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (argc != 3)
	{
		ft_printf ("❌ Wrong params\n💡 Usage: ./client <server_pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = confirm_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd ("❌ sigaction failed", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 100000)
	{
		ft_putendl_fd ("❌ Wrong PID", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	send_string(argv[2], ft_atoi(argv[1]));
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
