/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:15:49 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/21 13:41:25 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom_out(t_fractol *data, int x, int y)
{
	double	width;
	double	new_width;
	double	x_rescaled;
	double	y_rescaled;

	width = data->rb.re - data->lt.re;
	new_width = width * ZOOM_FACTOR;
	x_rescaled = data->lt.re + width * x / MAX_WIDTH;
	y_rescaled = data->lt.im + width * y / MAX_WIDTH;
	data->lt.re = x_rescaled - (x_rescaled - data->lt.re) * ZOOM_FACTOR;
	data->lt.im = y_rescaled - (y_rescaled - data->lt.im) * ZOOM_FACTOR;
	data->rb.re = data->lt.re + new_width;
	data->rb.im = data->lt.im + new_width;
}

static void	zoom_in(t_fractol *data, int x, int y)
{
	double	width;
	double	new_width;
	double	x_rescaled;
	double	y_rescaled;

	width = data->rb.re - data->lt.re;
	new_width = width / ZOOM_FACTOR;
	x_rescaled = data->lt.re + width * x / MAX_WIDTH;
	y_rescaled = data->lt.im + width * y / MAX_WIDTH;
	data->lt.re = x_rescaled - (x_rescaled - data->lt.re) / ZOOM_FACTOR;
	data->lt.im = y_rescaled - (y_rescaled - data->lt.im) / ZOOM_FACTOR;
	data->rb.re = data->lt.re + new_width;
	data->rb.im = data->lt.im + new_width;
}

static void	change_julia_c(int x, int y, t_fractol *data)
{
	double	width;
	double	x_rescaled;
	double	y_rescaled;

	width = data->rb.re - data->lt.re;
	x_rescaled = data->lt.re + width * x / MAX_WIDTH;
	y_rescaled = data->lt.im + width * y / MAX_WIDTH;
	data->julia_c.re = x_rescaled;
	data->julia_c.im = y_rescaled;
}

int	mouse_hook(int button, int x, int y, t_fractol *data)
{
	if (data->fractal_type == 2 && button == 1)
		change_julia_c(x, y, data);
	if (button == 4)
		zoom_out(data, x, y);
	else if (button == 5)
		zoom_in(data, x, y);
	render(data);
	return (0);
}

int	key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 29)
		data->color_scheme = 0;
	else if (18 <= keycode && keycode <= 21)
		data->color_scheme = keycode - 17;
	else if (keycode == 23)
		data->color_scheme = 5;
	else if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125
		|| keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
		move(data, keycode);
	else if (keycode == 116)
		data->max_iteration++;
	else if (keycode == 121)
		data->max_iteration--;
	render(data);
	return (0);
}
