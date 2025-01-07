/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:20:35 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/06 14:59:20 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_error(void)
{
	ft_putstr_fd("Problem with init functions of mlx\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	cord_init(t_data *fractol)
{
	fractol->cord.zoom = 1.0;
	fractol->cord.move_x = 0.0;
	fractol->cord.move_y = 0.0;
	fractol->iteration = 100;
}

void	events_init(t_data *fractol)
{
	mlx_hook(fractol->mlx.window, KEYPRESS, 0, key_handler, fractol);
	mlx_hook(fractol->mlx.window, BUTTONPRESS, 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx.window, DESTROYNOTIFY, 0, close_handler, fractol);
}

void	init_data(t_data *fractol)
{
	fractol->mlx.connection = mlx_init();
	if (fractol->mlx.connection == NULL)
		init_error();
	fractol->mlx.window = mlx_new_window(fractol->mlx.connection, WIN_WIDTH,
			WIN_HEIGHT, fractol->name);
	if (fractol->mlx.window == NULL)
	{
		init_error();
	}
	fractol->img.img = mlx_new_image(fractol->mlx.connection, WIN_WIDTH,
			WIN_HEIGHT);
	if (fractol->img.img == NULL)
	{
		mlx_destroy_window(fractol->mlx.connection, fractol->mlx.window);
		init_error();
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	cord_init(fractol);
	events_init(fractol);
}
