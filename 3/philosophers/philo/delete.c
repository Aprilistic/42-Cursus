/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 19:34:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	delete_data(t_data *data)
{
	if (data->philosophers)
		free(data->philosophers);
	if (data->forks_key)
		free(data->forks_key);
	if (data->forks)
		free(data->forks);
}

//mode  forks : 0, print : 1
int	delete_mutex(t_data *data, int mode)
{
	int	idx;
	int	error_flag;

	idx = 0;
	error_flag = 0;
	if (mode == 0)
	{
		while (idx < data->rule.number_of_philosophers)
		{
			if (pthread_mutex_destroy(&data->forks_key[idx]))
				error_flag |= write(2, "pthread_mutex_destroy() failed.\n", 32);
			idx++;
		}
		if (error_flag)
			return (_FUNCTIONAL_ERROR);
	}
	else if (mode == 1)
	{
		if (pthread_mutex_destroy(&data->print_key))
		{
			write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n", 32);
			return (_FUNCTIONAL_ERROR);
		}
	}
	return (0);
}

void	induce_thread_exit(t_data *data)
{
	data->running = 1;
	usleep(10 * MILI_SEC);
	data->running = 0;
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
	error_flag |= delete_mutex(data, 0);
	error_flag |= delete_mutex(data, 1);
	delete_data(data);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
