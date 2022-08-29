/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:29:10 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/20 19:26:25 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_diverging(t_complex *z)
{
	if (z->re * z->re + z->im * z->im > 4.0)
		return (1);
	return (0);
}

int	mandelbrot_formula(t_complex z, t_complex c, int max_iteration)
{
	int			iteration;
	t_complex	tmp;

	iteration = 0;
	while (iteration < max_iteration)
	{
		if (is_diverging(&z))
			break ;
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z = tmp;
		iteration++;
	}
	return (iteration);
}

int	julia_formula(t_complex z, t_complex c, int max_iteration)
{
	int			iteration;
	t_complex	tmp;

	iteration = 0;
	while (iteration < max_iteration)
	{
		if (is_diverging(&z))
			break ;
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z = tmp;
		iteration++;
	}
	return (iteration);
}

int	burningship_formula(t_complex z, t_complex c, int max_iteration)
{
	int			iteration;
	t_complex	tmp;

	iteration = 0;
	while (iteration < max_iteration)
	{
		if (is_diverging(&z))
			break ;
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		if (tmp.re < 0)
			tmp.re *= -1;
		if (tmp.im < 0)
			tmp.im *= -1;
		z = tmp;
		iteration++;
	}
	return (iteration);
}
