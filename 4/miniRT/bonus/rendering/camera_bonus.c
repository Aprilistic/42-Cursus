/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeypark <taeypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:36:04 by jinheo            #+#    #+#             */
/*   Updated: 2023/03/03 22:24:53 by taeypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_bonus.h"
#include "macro_bonus.h"
#include "struct_bonus.h"
#include <math.h>

void	camera_location_move(t_mlx *mlx, int keycode)
{
	t_vec3	*cam_location;

	cam_location = &mlx->camera.origin;
	if (keycode == LEFT_ARROW_KEY)
		*cam_location = v_sub(*cam_location, mlx->camera.u);
	else if (keycode == RIGHT_ARROW_KEY)
		*cam_location = v_add(*cam_location, mlx->camera.u);
	else if (keycode == DOWN_ARROW_KEY)
		*cam_location = v_sub(*cam_location, mlx->camera.dir);
	else if (keycode == UP_ARROW_KEY)
		*cam_location = v_add(*cam_location, mlx->camera.dir);
	else if (keycode == PAGE_DOWN_KEY)
		*cam_location = v_sub(*cam_location, mlx->camera.v);
	else if (keycode == PAGE_UP_KEY)
		*cam_location = v_add(*cam_location, mlx->camera.v);
}

int	camera_fov_change(t_mlx *mlx, int keycode)
{
	if (keycode == SCROLL_UP)
	{
		if (mlx->camera.fov >= 180)
			return (0);
		mlx->camera.fov += 5;
	}
	else if (keycode == SCROLL_DOWN)
	{
		if (mlx->camera.fov <= 0)
			return (0);
		mlx->camera.fov -= 5;
	}
	if (mlx->camera.fov > 180)
		mlx->camera.fov = 180;
	else if (mlx->camera.fov < 0)
		mlx->camera.fov = 0;
	return (1);
}
