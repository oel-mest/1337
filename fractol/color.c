/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:48:19 by oel-mest          #+#    #+#             */
/*   Updated: 2024/12/27 17:32:13 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	r_color(int i)
{
	unsigned int	gradient[22];

	gradient[0] = 0x0000008B;
	gradient[1] = 0x00003366;
	gradient[2] = 0x00005577;
	gradient[3] = 0x00007788;
	gradient[4] = 0x00009999;
	gradient[5] = 0x0011AA88;
	gradient[6] = 0x0022BB77;
	gradient[7] = 0x0033CC66;
	gradient[8] = 0x0044DD55;
	gradient[9] = 0x0055EE44;
	gradient[10] = 0x0066FF33;
	gradient[11] = 0x0077FF22;
	gradient[12] = 0x0088FF11;
	gradient[13] = 0x0099FF00;
	gradient[14] = 0x00AAEE11;
	gradient[15] = 0x00BBCC22;
	gradient[16] = 0x00CCAA33;
	gradient[17] = 0x00DD8855;
	gradient[18] = 0x00EE6677;
	gradient[19] = 0x00FF4499;
	gradient[20] = 0x00FF22BB;
	gradient[21] = 0x00FF00DD;
	return (gradient[i]);
}

unsigned int	get_color(int iter, int max_iter)
{
	double	value;
	int		index;

	value = (double)iter / (double)max_iter;
	index = (int)(value * 21);
	return (r_color(index));
}
