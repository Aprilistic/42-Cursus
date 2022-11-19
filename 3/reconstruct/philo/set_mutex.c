/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:24:49 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/18 15:59:12 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	set_order_key(t_data *data)
{
	int	ret;
	int	idx;
	int	i;

	ret = 0;
	idx = 0;
	i = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->philosophers[idx].order_key), NULL))
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
			ret = _FUNCTIONAL_ERROR;
			while (i < idx)
			{
				if (pthread_mutex_destroy(&(data->philosophers[i].order_key)))
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

static int	set_status_key(t_data *data)
{
	int	ret;
	int	idx;
	int	i;

	ret = 0;
	idx = 0;
	i = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->philosophers[idx].status_key), NULL))
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
			ret = _FUNCTIONAL_ERROR;
			while (i < idx)
			{
				if (pthread_mutex_destroy(&(data->philosophers[i].status_key)))
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

static int	set_forks(t_data *data)
{
	int	ret;
	int	idx;
	int	i;

	ret = 0;
	idx = 0;
	i = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[idx]), NULL))
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 29);
			ret = _FUNCTIONAL_ERROR;
			while (i < idx)
			{
				if (pthread_mutex_destroy(&(data->forks[i])))
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
	return (0);
}

int	set_mutex(t_data *data)
{
	if (set_order_key(data) == _FUNCTIONAL_ERROR)
	{
		return (_FUNCTIONAL_ERROR);
	}
	if (set_status_key(data) == _FUNCTIONAL_ERROR)
	{
		delete_mutex(data, 1);
		return (_FUNCTIONAL_ERROR);
	}
	if (set_forks(data) == _FUNCTIONAL_ERROR)
	{
		delete_mutex(data, 0);
		delete_mutex(data, 1);
		return (_FUNCTIONAL_ERROR);
	}
	if (set_print_key(data) == _FUNCTIONAL_ERROR)
	{
		delete_mutex(data, 0);
		delete_mutex(data, 1);
		delete_mutex(data, 2);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}
