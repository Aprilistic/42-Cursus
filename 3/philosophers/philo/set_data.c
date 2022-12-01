/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:49:55 by jinheo            #+#    #+#             */
/*   Updated: 2022/12/01 20:46:32 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//Memory allocation & parsing inputs

static int	ft_atoi(const char *str)
{
	long long	ret;

	ret = 0;
	while (*str)
	{
		if (*str < '0' || '9' < *str || ret > 2147483647)
			return (_INPUT_ERROR);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return ((int)ret);
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
		data->rule.recursion_count = ft_atoi(argv[5]);
	else
		data->rule.recursion_count = 2147483647;
	if (data->rule.number_of_philosophers == _INPUT_ERROR
		|| data->rule.time_to_die == _INPUT_ERROR
		|| data->rule.time_to_eat == _INPUT_ERROR
		|| data->rule.time_to_sleep == _INPUT_ERROR
		|| data->rule.recursion_count == _INPUT_ERROR)
		return (_INPUT_ERROR);
	return (0);
}

static int	set_memory(t_data *data)
{
	data->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->rule.number_of_philosophers);
	if (data->philosophers == NULL)
	{
		write(STDERR_FILENO, "malloc() failed.\n", 17);
		return (_FUNCTIONAL_ERROR);
	}
	data->forks_key = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->rule.number_of_philosophers);
	if (data->forks_key == NULL)
	{
		delete_data(data, 1);
		write(STDERR_FILENO, "malloc() failed.\n", 17);
		return (_FUNCTIONAL_ERROR);
	}
	data->forks = (int *)malloc(sizeof(int)
			* data->rule.number_of_philosophers);
	if (data->forks == NULL)
	{
		delete_data(data, 1 | 2);
		write(STDERR_FILENO, "malloc() failed.\n", 17);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

static void	set_default_value(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers[idx].parent_directory = data;
		data->philosophers[idx].philosopher_idx = idx;
		data->philosophers[idx].eating_count = 0;
		data->forks[idx] = 0;
		idx++;
	}
	data->running = 0;
}

int	set_data(t_data *data, int argc, char *argv[])
{
	if (set_rule(data, argc, argv) == _INPUT_ERROR)
	{
		return (_INPUT_ERROR);
	}
	if (set_memory(data) == _FUNCTIONAL_ERROR)
	{
		return (_FUNCTIONAL_ERROR);
	}
	set_default_value(data);
	return (0);
}
