/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:04:00 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 14:25:32 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	run_philosophers(t_data *data)
{
	int	idx;
	int	i;

	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_create(&(data->philosophers[idx].philosopher),
				NULL, &routine_philosopher,
				&(data->philosophers[idx])))
		{
			i = 0;
			while (i < idx)
			{
				if (pthread_detach(data->philosophers[idx].philosopher))
					write(STDERR_FILENO, "pthread_detach() failed.\n", 25);
				i++;
			}
			write(STDERR_FILENO, "pthread_create() failed.\n", 25);
			return (_FUNCTIONAL_ERROR);
		}
		idx++;
	}
	return (0);
}

static int	run_monitor(t_data *data)
{
	if (pthread_create(&(data->monitor), NULL, &routine_monitor, data))
	{
		write(STDERR_FILENO, "pthread_create() failed.\n", 25);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

static int	run_waiter(t_data *data)
{
	struct timeval	start_time;
	int				idx;

	gettimeofday(&start_time, NULL);
	data->start_time = start_time;
	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers[idx].think_since = start_time;
		idx++;
	}
	if (pthread_create(&(data->waiter), NULL, &routine_waiter, data) != 0)
	{
		write(STDERR_FILENO, "pthread_create() failed.\n", 25);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

int	run_threads(t_data *data)
{
	if (run_philosophers(data) == _FUNCTIONAL_ERROR)
	{
		delete_data(data);
		return (_FUNCTIONAL_ERROR);
	}
	if (run_monitor(data) == _FUNCTIONAL_ERROR)
	{
		delete_threads(data, 0);
		delete_data(data);
		return (_FUNCTIONAL_ERROR);
	}
	if (run_waiter(data) == _FUNCTIONAL_ERROR)
	{
		delete_threads(data, 0);
		delete_threads(data, 1);
		delete_data(data);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}
