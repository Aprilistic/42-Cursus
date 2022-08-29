/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:36:37 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/21 13:45:57 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, MAX_WIDTH, MAX_WIDTH, "fract-ol");
	data->img = mlx_new_image(data->mlx, MAX_WIDTH, MAX_WIDTH);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	julia_default(data);
	render(data);
}

void	hook(t_fractol *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (argc == 2
		&& (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "julia")
			|| !ft_strcmp(argv[1], "burningship")))
	{
		mlx_win_init(&data);
		if (!ft_strcmp(argv[1], "mandelbrot"))
			mandelbrot_default(&data);
		else if (!ft_strcmp(argv[1], "julia"))
			julia_default(&data);
		else
			burningship_default(&data);
		render(&data);
		hook(&data);
		mlx_loop(&data.mlx);
	}
	else
	{
		printf("Invalid input. Listing available parameters...\n");
		printf("1. mandelbrot\n");
		printf("2. julia\n");
		printf("3. burningship\n");
	}
	return (0);
}
