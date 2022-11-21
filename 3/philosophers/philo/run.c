/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:10:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/21 20:37:05 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	run_threads(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_create(&data->philosophers[idx].philosopher, NULL,
				&routine_philosopher, &data->philosophers[idx]))
		{
			write(STDERR_FILENO, "pthread_create() failed.\n", 25);
			induce_thread_exit(data);
			return (_FUNCTIONAL_ERROR);
		}
		idx++;
	}
	if (pthread_create(&data->monitor, NULL, &routine_monitor, data))
	{
		write(STDERR_FILENO, "pthread_create() failed.\n", 25);
		induce_thread_exit(data);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

int	running_status_check(t_data *data)
{
	int	ret;

	pthread_mutex_lock(&data->running_key);
	ret = data->running;
	pthread_mutex_unlock(&data->running_key);
	return (ret);
}

void	running_status_change(t_data *data, int change_to)
{
	pthread_mutex_lock(&data->running_key);
	data->running = change_to;
	pthread_mutex_unlock(&data->running_key);
}
