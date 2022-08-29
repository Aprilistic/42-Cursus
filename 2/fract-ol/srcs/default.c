/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:30:49 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/20 20:29:10 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	common_default(t_fractol *data)
{
	data->bits_per_pixel = 32;
	data->line_length = MAX_WIDTH * 4;
	data->endian = 1;
	data->max_iteration = 50;
	data->color_scheme = 0;
	data->julia_c.re = -0.4;
	data->julia_c.im = 0.6;
}

void	mandelbrot_default(t_fractol *data)
{
	common_default(data);
	data->fractal_type = 1;
	data->lt.re = -2.4;
	data->lt.im = -1.8;
	data->rb.re = 1.2;
	data->rb.im = 1.8;
}

void	julia_default(t_fractol *data)
{
	common_default(data);
	data->fractal_type = 2;
	data->lt.re = -1.8;
	data->lt.im = -1.8;
	data->rb.re = 1.8;
	data->rb.im = 1.8;
}

void	burningship_default(t_fractol *data)
{
	common_default(data);
	data->fractal_type = 3;
	data->lt.re = -2.4;
	data->lt.im = -1.8;
	data->rb.re = 1.2;
	data->rb.im = 1.8;
}
