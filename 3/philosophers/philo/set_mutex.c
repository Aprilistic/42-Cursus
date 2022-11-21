/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:24:49 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/21 20:17:11 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	set_forks_key(t_data *data)
{
	int	ret;
	int	idx;
	int	i;

	ret = 0;
	idx = 0;
	i = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks_key[idx]), NULL))
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
			ret = _FUNCTIONAL_ERROR;
			while (i < idx)
			{
				if (pthread_mutex_destroy(&(data->forks_key[i])))
					write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n",
						32);
				i++;
			}
			break ;
		}
		idx++;
	}
	return (ret);
}

static int	set_time_key(t_data *data)
{
	int	ret;
	int	idx;
	int	i;

	ret = 0;
	idx = 0;
	i = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->philosophers[idx].time_key), NULL))
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
			ret = _FUNCTIONAL_ERROR;
			while (i < idx)
			{
				if (pthread_mutex_destroy(&(data->philosophers[idx].time_key)))
					write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n",
						32);
				i++;
			}
			break ;
		}
		idx++;
	}
	return (ret);
}

static int	set_count_key(t_data *data)
{
	int	ret;
	int	idx;
	int	i;

	ret = 0;
	idx = 0;
	i = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->philosophers[idx].count_key), NULL))
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
			ret = _FUNCTIONAL_ERROR;
			while (i < idx)
			{
				if (pthread_mutex_destroy(&(data->philosophers[idx].count_key)))
					write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n",
						32);
				i++;
			}
			break ;
		}
		idx++;
	}
	return (ret);
}

static int	set_print_key(t_data *data)
{
	if (pthread_mutex_init(&(data->print_key), NULL))
	{
		write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
		return (_FUNCTIONAL_ERROR);
	}
	if (pthread_mutex_init(&data->running_key, NULL))
	{
		if (pthread_mutex_destroy(&data->print_key))
			write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n", 32);
		write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

int	set_mutex(t_data *data)
{
	if (set_forks_key(data) == _FUNCTIONAL_ERROR)
	{
		return (_FUNCTIONAL_ERROR);
	}
	if (set_time_key(data) == _FUNCTIONAL_ERROR)
	{
		delete_mutex(data, 1);
		return (_FUNCTIONAL_ERROR);
	}
	if (set_count_key(data) == _FUNCTIONAL_ERROR)
	{
		delete_mutex(data, 1 | 2);
		return (_FUNCTIONAL_ERROR);
	}
	if (set_print_key(data) == _FUNCTIONAL_ERROR)
	{
		delete_mutex(data, 1 | 2 | 4);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}
