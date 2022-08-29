/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:46:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/21 13:41:18 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define MAX_WIDTH 960
# define ZOOM_FACTOR 1.2

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			max_iteration;
	int			color_scheme;
	int			fractal_type;
	t_complex	lt;
	t_complex	rb;
	t_complex	julia_c;
}	t_fractol;

//main.c
void	mlx_win_init(t_fractol *data);

//render.c
void	render(t_fractol *data);

//pixel.c
void	calculate_pixel_color(t_fractol *data, int y, int x);

//color.c
int		create_trgb(int t, int r, int g, int b);

//palette.c
int		color_scheme_1(int max_iteration, int iteration);
int		color_scheme_2(int max_iteration, int iteration);
int		color_scheme_3(int max_iteration, int iteration);
int		color_scheme_4(int max_iteration, int iteration);
int		color_scheme_5(int max_iteration, int iteration);

//formula.c
int		mandelbrot_formula(t_complex z, t_complex c, int max_iteration);
int		julia_formula(t_complex z, t_complex c, int max_iteration);
int		burningship_formula(t_complex z, t_complex c, int max_iteration);

//default.c
void	mandelbrot_default(t_fractol *data);
void	julia_default(t_fractol *data);
void	burningship_default(t_fractol *data);

//hook.c
int		key_hook(int keycode, t_fractol *data);
int		mouse_hook(int button, int x, int y, t_fractol *data);

//move.c
void	move(t_fractol *data, int keycode);

//from_libft.c
int		ft_strcmp(char *s1, char *s2);

#endif
