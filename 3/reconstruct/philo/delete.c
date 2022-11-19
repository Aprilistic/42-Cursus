/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/19 16:47:47 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	delete_data(t_data *data)
{
	if (data->philosophers)
		free(data->philosophers);
	if (data->forks)
		free(data->forks);
}

//mode  order : 0, status : 1, forks : 2, print : 3
int	delete_mutex(t_data *data, int mode)
{
	int				idx;
	int				error_flag;
	pthread_mutex_t	*target;

	idx = 0;
	error_flag = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (mode == 0)
			target = &(data->philosophers[idx].order_key);
		else if (mode == 1)
			target = &(data->philosophers[idx].status_key);
		else if (mode == 2)
			target = &(data->forks[idx]);
		else if (mode == 3)
			target = &(data->print_key);
		if (pthread_mutex_destroy(target))
			error_flag |= write(2, "pthread_mutex_destroy() failed.\n", 32);
		if (mode == 3)
			break ;
		idx++;
	}
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}

//mode  philosophers : 0, monitor : 1, waiter : 2
int	delete_threads(t_data *data, int mode)
{
	int			idx;
	int			error;
	pthread_t	*target;

	idx = 0;
	error = 0;
	if (mode == 0)
	{
		while (idx < data->rule.number_of_philosophers)
		{
			if (pthread_detach(data->philosophers[idx].philosopher))
				error |= write(STDERR_FILENO,
						"pthread_mutex_destroy() failed.\n", 32);
			idx++;
		}
	}
	else if (mode == 1)
		target = &(data->monitor);
	else if (mode == 2)
		target = &(data->waiter);
	if ((mode & 3) && pthread_detach(*target))
		error |= write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n", 32);
	if (error)
		return (_FUNCTIONAL_ERROR);
	return (0);
}

int	kill_switch(t_data *data)
{
	int	idx;
	int	ret;

	idx = 0;
	ret = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		pthread_mutex_lock(&(data->philosophers[idx].status_key));
		data->philosophers[idx].status = ABORT;
		pthread_mutex_unlock(&(data->philosophers[idx].status_key));
		idx++;
	}
	usleep(10 * MILI_SEC);
	ret |= delete_threads(data, 0);
	ret |= delete_threads(data, 1);
	ret |= delete_threads(data, 2);
	usleep(10 * MILI_SEC);
	ret |= delete_mutex(data, 0);
	ret |= delete_mutex(data, 1);
	ret |= delete_mutex(data, 2);
	ret |= delete_mutex(data, 3);
	delete_data(data);
	if (ret)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
