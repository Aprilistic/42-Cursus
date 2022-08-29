/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:56:52 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/21 12:57:53 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	get_image(t_fractol *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < MAX_WIDTH)
	{
		x = 0;
		while (x < MAX_WIDTH)
		{
			calculate_pixel_color(data, y, x);
			x++;
		}
		y++;
	}
}

void	render(t_fractol *data)
{
	get_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
