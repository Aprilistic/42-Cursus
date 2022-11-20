/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:06:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 20:18:31 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	grab(t_data *data, int philosopher_idx)
{
	int				left;
	int				right;
	struct timeval	now;

	left = philosopher_idx;
	right = get_next_index(data->rule.number_of_philosophers, philosopher_idx,
			1);
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
	if (philosopher_idx % 2 == 0)
	{
		pthread_mutex_lock(&data->forks_key[left]);
		gettimeofday(&now, NULL);
		data->forks[left] = 1;
		print_message(data, &now, philosopher_idx, TAKEN);
	}
}

static void	release(t_data *data, int philosopher_idx)
{
	int	left;
	int	right;

	left = philosopher_idx;
	right = (philosopher_idx + 1) % data->rule.number_of_philosophers;
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
	info->eating_count++;
	gettimeofday(&now, NULL);
	print_message(data, &now, philosopher_idx, EATING);
	usleep(data->rule.time_to_eat * MILI_SEC);
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
	usleep(data->rule.time_to_sleep * MILI_SEC);
	gettimeofday(&now, NULL);
	info->think_since = now;
	print_message(data, &now, philosopher_idx, THINKING);
	usleep(data->rule.time_to_die / 2 * MILI_SEC);
}

void	*routine_philosopher(void *args)
{
	t_philosopher	*info;
	t_data			*data;

	info = (t_philosopher *)args;
	data = info->parent_directory;
	while (!data->running)
	{
	}
	if (info->philosopher_idx & 1)
		usleep(data->rule.time_to_eat / 2 * MILI_SEC);
	while (data->running)
	{
		grab(info->parent_directory, info->philosopher_idx);
		eat(info);
		release(info->parent_directory, info->philosopher_idx);
		if (info->eating_count >= data->rule.recursion_count || !data->running)
			break ;
		sleep_and_think(info);
	}
	return (NULL);
}
