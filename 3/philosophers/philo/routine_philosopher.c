/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:06:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/26 15:11:29 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	grab(t_data *data, int philosopher_idx)
{
	int				left;
	int				right;
	struct timeval	now;

	left = philosopher_idx;
	right = (philosopher_idx + 1) % data->rule.number_of_philosophers;
	if (philosopher_idx % 2)
	{
		pthread_mutex_lock(&data->forks_key[left]);
		gettimeofday(&now, NULL);
		data->forks[left] = 1;
		print_message(data, &now, philosopher_idx, TAKEN);
	}
	pthread_mutex_lock(&data->forks_key[right]);
	gettimeofday(&now, NULL);
	data->forks[right] = 1;
	print_message(data, &now, philosopher_idx, TAKEN);
	if (solo_deadlock_exception(data) || philosopher_idx % 2)
		return ;
	pthread_mutex_lock(&data->forks_key[left]);
	gettimeofday(&now, NULL);
	data->forks[left] = 1;
	print_message(data, &now, philosopher_idx, TAKEN);
}

static void	release(t_data *data, int philosopher_idx)
{
	int	left;
	int	right;

	left = philosopher_idx;
	right = (philosopher_idx + 1) % data->rule.number_of_philosophers;
	if (data->rule.number_of_philosophers == 1)
		return ;
	if (philosopher_idx % 2)
	{
		data->forks[left] = 0;
		pthread_mutex_unlock(&data->forks_key[left]);
	}
	data->forks[right] = 0;
	pthread_mutex_unlock(&data->forks_key[right]);
	if (philosopher_idx % 2 == 0)
	{
		data->forks[left] = 0;
		pthread_mutex_unlock(&data->forks_key[left]);
	}
}

static void	eat(t_philosopher *info)
{
	t_data			*data;
	int				philosopher_idx;
	struct timeval	now;

	data = info->parent_directory;
	philosopher_idx = info->philosopher_idx;
	gettimeofday(&now, NULL);
	update_timestamp(info, &now);
	pthread_mutex_lock(&info->count_key);
	info->eating_count++;
	pthread_mutex_unlock(&info->count_key);
	print_message(data, &now, philosopher_idx, EATING);
	usleep(data->rule.time_to_eat * SLEEP_FACTOR * MILI_SEC);
	wait_till(&now, data->rule.time_to_eat);
}

static void	sleep_and_think(t_philosopher *info)
{
	t_data			*data;
	int				philosopher_idx;
	struct timeval	now;

	data = info->parent_directory;
	philosopher_idx = info->philosopher_idx;
	gettimeofday(&now, NULL);
	print_message(data, &now, philosopher_idx, SLEEPING);
	usleep(data->rule.time_to_sleep * SLEEP_FACTOR * MILI_SEC);
	wait_till(&now, data->rule.time_to_sleep);
	gettimeofday(&now, NULL);
	print_message(data, &now, philosopher_idx, THINKING);
}

void	*routine_philosopher(void *args)
{
	t_philosopher	*info;
	t_data			*data;

	info = (t_philosopher *)args;
	data = info->parent_directory;
	while (!running_status_check(data))
	{
	}
	if (info->philosopher_idx & 1)
		usleep(data->rule.time_to_eat * SLEEP_FACTOR * MILI_SEC);
	while (running_status_check(data))
	{
		grab(data, info->philosopher_idx);
		eat(info);
		release(data, info->philosopher_idx);
		if (info->eating_count >= data->rule.recursion_count
			|| !running_status_check(data))
			break ;
		sleep_and_think(info);
	}
	return (NULL);
}
