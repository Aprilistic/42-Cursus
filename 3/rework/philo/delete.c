/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/18 15:26:59 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	delete_data(t_data *data)
{
	if (data->philosophers)
		free(data->philosophers);
	if (data->monitors)
		free(data->monitors);
	if (data->waiter)
		free(data->waiter);
	if (data->forks)
		free(data->forks);
}

int	delete_threads(t_data *data)
{
	int	thread_idx;
	int	error_flag;

	error_flag = 0;
	thread_idx = 0;
	while (thread_idx < data->rule.number_of_philosophers)
	{
		if (pthread_join(data->philosophers[thread_idx].philosopher, NULL) != 0
			|| pthread_join(data->monitors[thread_idx], NULL) != 0)
			error_flag = write(STDERR_FILENO, "pthread_join() failed.\n", 23);
		if (pthread_mutex_destroy(&(data->forks[thread_idx])) != 0)
			error_flag = write(STDERR_FILENO,
					"pthread_mutex_destroy() failed.\n", 32);
		thread_idx++;
	}
	if (pthread_join(*(data->waiter), NULL) != 0)
		error_flag = write(STDERR_FILENO, "pthread_join() failed.\n", 23);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
