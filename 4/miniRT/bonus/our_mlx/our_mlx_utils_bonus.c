/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_mlx_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:34:47 by taeypark          #+#    #+#             */
/*   Updated: 2023/03/02 21:06:08 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_bonus.h"
#include "macro_bonus.h"

int	mouse_hook(int mouse_code, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (mouse_code == SCROLL_UP || mouse_code == SCROLL_DOWN)
	{
		if (camera_fov_change(mlx, mouse_code))
		{
			mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
			make_image(mlx);
		}
	}
	return (0);
}
