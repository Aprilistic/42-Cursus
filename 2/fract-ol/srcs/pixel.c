/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:15:47 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/20 21:34:12 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_complex	pixel_to_complex(t_fractol *data, int y, int x)
{
	t_complex	complex;

	complex.re = data->lt.re
		+ (data->rb.re - data->lt.re) * ((double)x / MAX_WIDTH);
	complex.im = data->lt.im
		+ (data->rb.im - data->lt.im) * ((double)y / MAX_WIDTH);
	return (complex);
}

//calculate iteration count at pixel by fractal formula.
static int	complex_to_iteration(t_fractol *data, t_complex complex)
{
	t_complex	tmp;
	int			iteration;

	iteration = 0;
	tmp.re = 0;
	tmp.im = 0;
	if (data->fractal_type == 1)
		iteration = mandelbrot_formula(tmp, complex, data->max_iteration);
	else if (data->fractal_type == 2)
		iteration = julia_formula(complex, data->julia_c, data->max_iteration);
	else if (data->fractal_type == 3)
		iteration = burningship_formula(tmp, complex, data->max_iteration);
	return (iteration);
}

//later, we can choose pallete. for now, just black and white.
static int	iteration_to_color(t_fractol *data, int iteration)
{
	int	color;

	if (iteration == data->max_iteration)
		color = 0x000000;
	else
		color = 6000 * iteration;
	if (data->color_scheme == 1)
		color = color_scheme_1(data->max_iteration, iteration);
	else if (data->color_scheme == 2)
		color = color_scheme_2(data->max_iteration, iteration);
	else if (data->color_scheme == 3)
		color = color_scheme_3(data->max_iteration, iteration);
	else if (data->color_scheme == 4)
		color = color_scheme_4(data->max_iteration, iteration);
	else if (data->color_scheme == 5)
		color = color_scheme_5(data->max_iteration, iteration);
	return (color);
}

static void	color_to_pixel(t_fractol *data, int y, int x, int color)
{
	char	*target;

	target = data->img_addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)target = color;
}

void	calculate_pixel_color(t_fractol *data, int y, int x)
{
	t_complex	complex;
	int			iteration;
	int			color;

	complex = pixel_to_complex(data, y, x);
	iteration = complex_to_iteration(data, complex);
	color = iteration_to_color(data, iteration);
	color_to_pixel(data, y, x, color);
}
