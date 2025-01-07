/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:05 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/04 14:44:26 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mandelbrot_step(t_complex z, t_complex c)
{
	t_complex	result;

	result.re = (z.re * z.re) - (z.im * z.im) + c.re;
	result.im = (2 * z.re * z.im) + c.im;
	return (result);
}

int	is_escaped(t_complex z)
{
	double	result;

	result = (z.re * z.re) + (z.im * z.im);
	if (result > 4)
		return (1);
	else
		return (0);
}

void	init_starting(t_complex *z, t_complex *c, t_data *fractol, t_pixel px)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		z->re = scale(px.x, -2, 2, WIN_WIDTH - 1) / fractol->cord.zoom
			+ fractol->cord.move_x;
		z->im = scale(px.y, 2, -2, WIN_HEIGHT - 1) / fractol->cord.zoom
			+ fractol->cord.move_y;
		c->re = fractol->cord.julia_x;
		c->im = fractol->cord.julia_y;
	}
	else
	{
		z->re = 0;
		z->im = 0;
		c->re = scale(px.x, -2, 2, WIN_WIDTH - 1) / fractol->cord.zoom
			+ fractol->cord.move_x;
		c->im = scale(px.y, 2, -2, WIN_HEIGHT - 1) / fractol->cord.zoom
			+ fractol->cord.move_y;
	}
}

void	handle_pixel(int x, int y, t_data *fractol)
{
	int			iter;
	t_complex	z;
	t_complex	c;
	int			color;
	t_pixel		px;

	px.x = x;
	px.y = y;
	init_starting(&z, &c, fractol, px);
	if (!ft_strcmp(fractol->name, "tricorn"))
		return (handle_tricorn(px, fractol, &z, &c));
	iter = 0;
	while (iter < fractol->iteration && !is_escaped(z))
	{
		z = mandelbrot_step(z, c);
		iter++;
	}
	if (iter == fractol->iteration)
		my_mlx_pixel_put(&fractol->img, x, y, 0x00000000);
	else
	{
		color = get_color(iter, fractol->iteration);
		my_mlx_pixel_put(&fractol->img, x, y, color);
	}
}

void	render_data(t_data *fractol)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx.connection, fractol->mlx.window,
		fractol->img.img, 0, 0);
}
