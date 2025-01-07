/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:44:41 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/05 19:23:34 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_data *fractol)
{
	if (keysym == 53)
		close_handler(fractol);
	if (keysym == 123)
		fractol->cord.move_x += (0.5 / fractol->cord.zoom);
	else if (keysym == 124)
		fractol->cord.move_x -= (0.5 / fractol->cord.zoom);
	else if (keysym == 126)
		fractol->cord.move_y -= (0.5 / fractol->cord.zoom);
	else if (keysym == 125)
		fractol->cord.move_y += (0.5 / fractol->cord.zoom);
	else if (keysym == 69)
		fractol->iteration += 10;
	else if (keysym == 78)
		if (fractol->iteration >= 10)
			fractol->iteration -= 10;
	render_data(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_data *fractol)
{
	double	cursor_re;
	double	cursor_im;

	cursor_re = scale(x, -2, 2, WIN_WIDTH - 1) / fractol->cord.zoom
		+ fractol->cord.move_x;
	cursor_im = scale(y, 2, -2, WIN_HEIGHT - 1) / fractol->cord.zoom
		+ fractol->cord.move_y;
	if (button == 5)
	{
		fractol->cord.zoom /= 1.05;
		fractol->cord.move_x -= (cursor_re - fractol->cord.move_x) * 0.05;
		fractol->cord.move_y -= (cursor_im - fractol->cord.move_y) * 0.05;
	}
	else if (button == 4)
	{
		fractol->cord.zoom *= 1.05;
		fractol->cord.move_x += (cursor_re - fractol->cord.move_x) * 0.05;
		fractol->cord.move_y += (cursor_im - fractol->cord.move_y) * 0.05;
	}
	render_data(fractol);
	return (0);
}

int	close_handler(t_data *fractol)
{
	mlx_destroy_image(fractol->mlx.connection, fractol->img.img);
	mlx_destroy_window(fractol->mlx.connection, fractol->mlx.window);
	exit(EXIT_SUCCESS);
}
