/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/23 21:14:19 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

//mode forks : 1, print : 2, running 4, count 8, time 16
static int	close_semaphore(t_data *data, int mode)
{
	int	error_flag;
	int	idx;

	error_flag = 0;
	idx = 0;
	if ((mode & 1) && sem_close(data->forks_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if ((mode & 2) && sem_close(data->print_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if ((mode & 4) && sem_close(data->running_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if (mode & (8 | 16))
	{
		while (idx < data->rule.number_of_philosophers)
		{
			if ((mode & 8) && sem_close(data->philosophers[idx].count_key))
				error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
			if ((mode & 16) && sem_close(data->philosophers[idx].time_key))
				error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
			idx++;
		}
	}
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}

//mode forks : 1, print : 2, running 4, count 8, time 16
static int	unlink_semaphore(t_data *data, int mode)
{
	int	error_flag;
	int	idx;

	error_flag = 0;
	idx = 0;
	if ((mode & 1) && sem_unlink("forks"))
			error_flag |= write(STDERR_FILENO, "sem_unlink failed\n", 18);
	if ((mode & 2) && sem_unlink("print"))
			error_flag |= write(STDERR_FILENO, "sem_unlink failed\n", 18);
	if ((mode & 4) && sem_unlink("running"))
			error_flag |= write(STDERR_FILENO, "sem_unlink failed\n", 18);
	if (mode & (8 | 16))
	{
		while (idx < data->rule.number_of_philosophers)
		{
			if ((mode & 8) && sem_unlink(data->philosophers[idx].count_key))
				error_flag |= write(STDERR_FILENO, "sem_unlink failed\n", 18);
			if ((mode & 16) && sem_unlink(data->philosophers[idx].time_key))
				error_flag |= write(STDERR_FILENO, "sem_unlink failed\n", 18);
			idx++;
		}
	}
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}

int	delete_semaphore(t_data *data, int mode)
{
	int	error_flag;

	error_flag = 0;
	error_flag |= close_semaphore(data, mode);
	error_flag |= unlink_semaphore(data, mode);
	if (error_flag == _FUNCTIONAL_ERROR)
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
