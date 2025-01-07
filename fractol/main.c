/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:20:40 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/06 14:50:58 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	validate_double(char *str)
{
	int	passed_p;

	passed_p = 0;
	if (NULL == str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (is_digit(*str))
			str++;
		else if (*str == '.' && !passed_p && is_digit(*(str + 1)))
		{
			str++;
			passed_p = 1;
		}
		else
			return (0);
	}
	return (1);
}

void	validate_julia(char *re, char *im)
{
	if (validate_double(re) && validate_double(im))
		return ;
	else
	{
		ft_putstr_fd("Please enter a valid julia point\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_data	fractol;

	fractol.name = av[1];
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4
			&& !ft_strcmp(av[1], "julia")))
	{
		if (!ft_strcmp(fractol.name, "julia"))
		{
			validate_julia(av[2], av[3]);
			fractol.cord.julia_x = ft_atof(av[2]);
			fractol.cord.julia_y = ft_atof(av[3]);
		}
		init_data(&fractol);
		render_data(&fractol);
		mlx_loop(fractol.mlx.connection);
	}
	else if (ac == 2 && !ft_strcmp(av[1], "tricorn"))
		draw_tricorn(&fractol);
	else
	{
		ft_putstr_fd("Usage : ./fractol mandelbrot\n", 2);
		ft_putstr_fd("\t./fractol julia <re> <im>\n\t./fractol tricorn\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
