/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:35:44 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/21 13:42:25 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	move_up(t_fractol *data)
{
	double	width;

	width = data->rb.re - data->lt.re;
	data->lt.im -= width / 8.0;
	data->rb.im -= width / 8.0;
}

static void	move_down(t_fractol *data)
{
	double	width;

	width = data->rb.re - data->lt.re;
	data->lt.im += width / 8.0;
	data->rb.im += width / 8.0;
}

static void	move_left(t_fractol *data)
{
	double	width;

	width = data->rb.re - data->lt.re;
	data->lt.re -= width / 8.0;
	data->rb.re -= width / 8.0;
}

static void	move_right(t_fractol *data)
{
	double	width;

	width = data->rb.re - data->lt.re;
	data->lt.re += width / 8.0;
	data->rb.re += width / 8.0;
}

void	move(t_fractol *data, int keycode)
{
	if (keycode == 13 || keycode == 126)
		move_up(data);
	else if (keycode == 1 || keycode == 125)
		move_down(data);
	else if (keycode == 0 || keycode == 123)
		move_left(data);
	else if (keycode == 2 || keycode == 124)
		move_right(data);
}
