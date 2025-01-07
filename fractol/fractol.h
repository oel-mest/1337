/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:38:09 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/06 15:12:31 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define KEYPRESS 2
# define BUTTONPRESS 4
# define DESTROYNOTIFY 17

typedef struct s_pixel
{
	int	x;
	int	y;
}				t_pixel;

typedef struct s_cord
{
	double		zoom;
	double		move_x;
	double		move_y;
	double		julia_x;
	double		julia_y;
}				t_cord;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_mlx
{
	void		*connection;
	void		*window;
}				t_mlx;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_data
{
	char		*name;
	t_mlx		mlx;
	t_img		img;
	t_cord		cord;
	int			iteration;
}				t_data;

void			init_data(t_data *fractol);
double			scale(int value, double min, double max, int end);
void			render_data(t_data *fractol);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				is_escaped(t_complex z);
int				close_handler(t_data *fractol);
int				mouse_handler(int button, int x, int y, t_data *fractol);
int				key_handler(int keysym, t_data *fractol);
double			ft_atof(char *str);
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr_fd(char *s, int fd);
unsigned int	get_smooth_color(int iteration, int max_iter, double z_re,
					double z_im);
unsigned int	get_color(int iter, int max_iter);
void			handle_tricorn(t_pixel px, t_data *fractol, t_complex *z,
					t_complex *c);
void			draw_tricorn(t_data *fractol);

#endif