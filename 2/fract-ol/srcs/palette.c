/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:43:39 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/21 13:31:11 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	color_scheme_1(int max_iteration, int iteration)
{
	int	block;
	int	color;

	block = 255.999 / (max_iteration / 2);
	if (iteration == max_iteration)
		color = 0x000000;
	else if (iteration < max_iteration / 2)
		color = create_trgb(0, block * iteration, 0, 0);
	else
	{
		color = create_trgb(0, 255, block * iteration, block * iteration);
	}
	return (color);
}

int	color_scheme_2(int max_iteration, int iteration)
{
	int	block;
	int	color;

	block = 255.999 / (max_iteration) * iteration;
	if (iteration == max_iteration)
		color = 0x000000;
	else
		color = create_trgb(0, block, block, block);
	return (color);
}

int	color_scheme_3(int max_iteration, int iteration)
{
	int	palette[5];

	palette[0] = 0x324759;
	palette[1] = 0xF3E0BE;
	palette[2] = 0xB19F8A;
	palette[3] = 0xFEFEFE;
	palette[4] = 0x687A86;
	if (iteration == max_iteration)
		return (0x000000);
	return (palette[iteration % 5]);
}

int	color_scheme_4(int max_iteration, int iteration)
{
	int	palette[5];

	palette[0] = 0x00E3BD;
	palette[1] = 0xFF1776;
	palette[2] = 0xFFCD00;
	palette[3] = 0x271E5D;
	palette[4] = 0x000000;
	if (iteration == max_iteration)
		return (0x000000);
	return (palette[iteration % 5]);
}

int	color_scheme_5(int max_iteration, int iteration)
{
	int	palette[5];

	palette[0] = 0x0D688C;
	palette[1] = 0xB8BFA8;
	palette[2] = 0xF2C641;
	palette[3] = 0xD9923B;
	palette[4] = 0x8C5C32;
	if (iteration == max_iteration)
		return (0xFFFFFF);
	return (palette[iteration % 5]);
}
