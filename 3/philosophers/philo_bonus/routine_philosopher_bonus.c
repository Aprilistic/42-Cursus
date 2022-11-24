/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosopher_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:06:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/24 21:51:19 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	grab(t_data *data, int philosopher_idx)
{
	struct timeval	now;

	sem_wait(data->forks_key);
	gettimeofday(&now, NULL);
	if (get_time_difference_in_ms(
			&data->philosophers[philosopher_idx].last_status_change,
			&now) >= data->rule.time_to_die)
	{
		print_message(data, &now, philosopher_idx, DEAD);
		sem_post(data->forks_key);
		exit(0);
	}
	print_message(data, &now, philosopher_idx, TAKEN);
	sem_wait(data->forks_key);
	gettimeofday(&now, NULL);
	if (get_time_difference_in_ms(
			&data->philosophers[philosopher_idx].last_status_change,
			&now) >= data->rule.time_to_die)
	{
		print_message(data, &now, philosopher_idx, DEAD);
		sem_post(data->forks_key);
		sem_post(data->forks_key);
		exit(0);
	}
	print_message(data, &now, philosopher_idx, TAKEN);
}

static void	release(t_data *data)
{
	sem_post(data->forks_key);
	sem_post(data->forks_key);
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
	info->eating_count++;
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
	update_timestamp(info, &now);
	print_message(data, &now, philosopher_idx, SLEEPING);
	usleep(data->rule.time_to_sleep * SLEEP_FACTOR * MILI_SEC);
	wait_till(&now, data->rule.time_to_sleep);
	gettimeofday(&now, NULL);
	update_timestamp(info, &now);
	print_message(data, &now, philosopher_idx, THINKING);
	usleep(data->rule.time_to_die * SLEEP_FACTOR * MILI_SEC);
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
		release(data);
		if (info->eating_count >= data->rule.recursion_count
			|| !running_status_check(data))
			exit(0);
		sleep_and_think(info);
	}
	return (NULL);
}
