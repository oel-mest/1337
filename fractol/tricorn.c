/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:40 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/04 14:52:04 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_tricorn(t_data *fractol)
{
	init_data(fractol);
	render_data(fractol);
	mlx_loop(fractol->mlx.connection);
}

t_complex	tricorn_step(t_complex *z, t_complex *c)
{
	t_complex	result;

	result.re = z->re * z->re - z->im * z->im + c->re;
	result.im = -2 * z->re * z->im + c->im;
	return (result);
}

void	handle_tricorn(t_pixel px, t_data *fractol, t_complex *z,
		t_complex *c)
{
	int	color;
	int	iter;

	iter = 0;
	while (iter < fractol->iteration && !is_escaped(*z))
	{
		*z = tricorn_step(z, c);
		iter++;
	}
	if (iter == fractol->iteration)
		my_mlx_pixel_put(&fractol->img, px.x, px.y, 0x00000000);
	else
	{
		color = get_color(iter, fractol->iteration);
		my_mlx_pixel_put(&fractol->img, px.x, px.y, color);
	}
}
