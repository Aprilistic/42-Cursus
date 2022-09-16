/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:27:26 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/16 18:36:47 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	grab_fork();

void	philosopher_routine(t_philosopher *thread)
{
	while (1)
	{
		if ((*thread).order == AUTHORIZED)
		{
			grab_fork();
			eating();
			put_fork();
			sleeping();
			thinking();
		}
	}
}
