/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/23 19:59:59 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//mode philosophers : 1, forks_key : 2, forks : 4
void	delete_data(t_data *data, int mode)
{
	if ((mode & 1) && data->philosophers)
		free(data->philosophers);
	if ((mode & 2) && data->forks_key)
		free(data->forks_key);
	if ((mode & 4) && data->forks)
		free(data->forks);
}

//mode  forks : 1, time : 2, count : 4, print : 8
int	delete_mutex(t_data *data, int mode)
{
	int	idx;
	int	error_flag;

	idx = -1;
	error_flag = 0;
	if (mode & (1 | 2 | 4))
	{
		while (++idx < data->rule.number_of_philosophers)
		{
			if (mode & 1 && pthread_mutex_destroy(&data->forks_key[idx]))
				error_flag |= write(2, "pthread_mutex_destroy() failed.\n", 32);
			if (mode & 2
				&& pthread_mutex_destroy(&data->philosophers[idx].time_key))
				error_flag |= write(2, "pthread_mutex_destroy() failed.\n", 32);
			if (mode & 4
				&& pthread_mutex_destroy(&data->philosophers[idx].count_key))
				error_flag |= write(2, "pthread_mutex_destroy() failed.\n", 32);
		}
	}
	if ((mode & 8) && (pthread_mutex_destroy(&data->print_key)
			|| pthread_mutex_destroy(&data->running_key)))
		error_flag |= write(2, "pthread_mutex_destroy() failed.\n", 32);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}

void	induce_thread_exit(t_data *data)
{
	running_status_change(data, 1);
	usleep(100 * MILI_SEC);
	running_status_change(data, 0);
}

int	retrieve_resource(t_data *data)
{
	int	idx;
	int	ret;
	int	error_flag;

	idx = 0;
	error_flag = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		ret = pthread_join(data->philosophers[idx].philosopher, NULL);
		if (ret)
			error_flag |= write(STDERR_FILENO, "pthread_join() failed.\n", 23);
		idx++;
	}
	ret = pthread_join(data->monitor, NULL);
	if (ret)
		error_flag |= write(STDERR_FILENO, "pthread_join() failed.\n", 23);
	usleep(100 * MILI_SEC);
	error_flag |= delete_mutex(data, 1 | 2 | 4 | 8);
	delete_data(data, 1 | 2 | 4);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
