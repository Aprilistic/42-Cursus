/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:18:20 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/27 18:03:01 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	begin_supper(t_data *data)
{
	int				idx;
	struct timeval	now;

	idx = 0;
	gettimeofday(&now, NULL);
	data->start_time = now;
	while (idx < data->rule.number_of_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[idx].time_key);
		data->philosophers[idx].last_status_change = now;
		pthread_mutex_unlock(&data->philosophers[idx].time_key);
		idx++;
	}
	running_status_change(data, 1);
}

static int	full_check(t_data *data)
{
	int	idx;
	int	eating_count;
	int	all_full;

	idx = 0;
	all_full = 1;
	while (idx < data->rule.number_of_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[idx].count_key);
		eating_count = data->philosophers[idx].eating_count;
		pthread_mutex_unlock(&data->philosophers[idx].count_key);
		if (eating_count < data->rule.recursion_count)
		{
			all_full = 0;
			break ;
		}
		idx++;
	}
	return (all_full);
}

static int	dead_check(t_data *data, struct timeval *now, int idx)
{
	struct timeval	last_status_change;
	int				dead;

	dead = 0;
	pthread_mutex_lock(&data->philosophers[idx].time_key);
	last_status_change = data->philosophers[idx].last_status_change;
	pthread_mutex_unlock(&data->philosophers[idx].time_key);
	pthread_mutex_lock(&data->philosophers[idx].count_key);
	if (get_time_difference_in_ms(&last_status_change, now)
		>= data->rule.time_to_die
		&& data->philosophers[idx].eating_count < data->rule.recursion_count)
		dead = 1;
	pthread_mutex_unlock(&data->philosophers[idx].count_key);
	return (dead);
}

void	*routine_monitor(void *args)
{
	t_data			*data;
	int				idx;
	struct timeval	now;

	data = (t_data *)args;
	begin_supper(data);
	while (running_status_check(data))
	{
		gettimeofday(&now, NULL);
		idx = 0;
		while (idx < data->rule.number_of_philosophers)
		{
			if (full_check(data))
				return (NULL);
			if (dead_check(data, &now, idx))
			{
				print_message(data, &now, idx, DEAD);
				return (NULL);
			}
			idx++;
		}
		usleep(500);
	}
	return (NULL);
}
