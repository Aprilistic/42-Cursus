/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:10:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/24 21:13:48 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	running_status_check(t_data *data)
{
	int	ret;

	sem_wait(data->running_key);
	ret = data->running;
	sem_post(data->running_key);
	return (ret);
}

void	running_status_change(t_data *data, int change_to)
{
	sem_wait(data->running_key);
	data->running = change_to;
	sem_post(data->running_key);
}

void	run_thread(t_philosopher *info)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &routine_philosopher, info))
	{
		write(STDERR_FILENO, "pthread_create() failed.\n", 25);
		exit(_FUNCTIONAL_ERROR);
	}
}
