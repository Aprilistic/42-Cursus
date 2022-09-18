/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:49:55 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/18 15:28:07 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_atoi(const char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (_INPUT_ERROR);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret);
}

static int	set_rule(t_data *data, int argc, char *argv[])
{
	if (argc < 5 || 6 < argc)
		return (_INPUT_ERROR);
	data->rule.number_of_philosophers = ft_atoi(argv[1]);
	data->rule.time_to_die = ft_atoi(argv[2]);
	data->rule.time_to_eat = ft_atoi(argv[3]);
	data->rule.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->rule.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->rule.time_to_sleep = 0;
	if (data->rule.number_of_philosophers == _INPUT_ERROR
		|| data->rule.time_to_die == _INPUT_ERROR
		|| data->rule.time_to_eat == _INPUT_ERROR
		|| data->rule.time_to_sleep == _INPUT_ERROR)
		return (_INPUT_ERROR);
	return (0);
}

static int	set_threads(t_data *data)
{
	data->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->rule.number_of_philosophers);
	data->monitors = (pthread_t *)malloc(sizeof(pthread_t)
			* data->rule.number_of_philosophers);
	data->waiter = (pthread_t *)malloc(sizeof(pthread_t));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->rule.number_of_philosophers);
	if (data->philosophers == NULL || data->monitors == NULL
		|| data->waiter == NULL || data->forks == NULL)
	{
		write(STDERR_FILENO, "malloc() failed.\n", 17);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

static int	set_mutex(t_data *data)
{
	int	idx;
	int	tmp;

	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[idx]), NULL) != 0)
		{
			write(STDERR_FILENO, "pthread_mutex_init() failed.\n", 28);
			tmp = 0;
			while (tmp < idx)
			{
				if (pthread_mutex_destroy(&(data->forks[idx])) != 0)
					write(STDERR_FILENO, "pthread_mutex_destroy() failed.\n",
						32);
				tmp++;
			}
			return (_FUNCTIONAL_ERROR);
		}
		idx++;
	}
	return (0);
}

int	set_data(t_data *data, int argc, char *argv[])
{
	if (set_rule(data, argc, argv) == _INPUT_ERROR)
		return (_INPUT_ERROR);
	if (set_threads(data) == _FUNCTIONAL_ERROR)
	{
		delete_data(data);
		return (_FUNCTIONAL_ERROR);
	}
	if (set_mutex(data) == _FUNCTIONAL_ERROR)
	{
		delete_data(data);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}
