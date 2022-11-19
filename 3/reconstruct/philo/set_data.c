/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:49:55 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/19 16:57:43 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//Memory allocation & parsing inputs

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
		data->rule.recursion_count = ft_atoi(argv[5]);
	else
		data->rule.recursion_count = 987654321;
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
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->rule.number_of_philosophers);
	if (data->forks == NULL)
	{
		free(data->philosophers);
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
		data->philosophers->parent_directory = data;
		data->philosophers[idx].philosopher_idx = idx;
		data->philosophers[idx].order = UNAUTHORIZED;
		data->philosophers[idx].status = WAITING;
		data->philosophers[idx].left_fork = 0;
		data->philosophers[idx].right_fork = 0;
		data->philosophers->eating_count = 0;
		idx++;
	}
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
