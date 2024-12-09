/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:08 by oel-mest          #+#    #+#             */
/*   Updated: 2024/09/04 12:49:41 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	argc = 0;
	i = 0;
	while (argv[argc][i])
	{
		write (1, &argv[argc][i], 1);
		i++;
	}
	write (1, "\n", 1);
}
