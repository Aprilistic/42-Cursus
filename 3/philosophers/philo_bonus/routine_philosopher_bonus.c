/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosopher_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:06:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/12/03 20:46:29 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	grab(t_data *data, int philosopher_idx)
{
	struct timeval	now;

	sem_wait(data->forks_key);
	gettimeofday(&now, NULL);
	print_message(data, &now, philosopher_idx, TAKEN);
	sem_wait(data->forks_key);
	gettimeofday(&now, NULL);
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
	wait_till_begin(info);
	if (info->philosopher_idx % 2)
		usleep(data->rule.time_to_eat * 0.5 * MILI_SEC);
	while (1)
	{
		grab(data, info->philosopher_idx);
		eat(info);
		release(data);
		if (info->eating_count >= data->rule.recursion_count)
			exit(0);
		sleep_and_think(info);
	}
	return (NULL);
}
