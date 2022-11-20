/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:06:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 14:27:44 by jinheo           ###   ########.fr       */
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
		pthread_mutex_lock(&data->forks[left]);
		gettimeofday(&now, NULL);
		print_message(data, &now, philosopher_idx, TAKEN);
	}
	pthread_mutex_lock(&data->forks[right]);
	gettimeofday(&now, NULL);
	print_message(data, &now, philosopher_idx, TAKEN);
	if (philosopher_idx % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[left]);
		gettimeofday(&now, NULL);
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
		pthread_mutex_unlock(&data->forks[left]);
	}
	pthread_mutex_unlock(&data->forks[right]);
	if (philosopher_idx % 2 == 0)
	{
		pthread_mutex_unlock(&data->forks[left]);
	}
}

static void	eat(t_philosopher *info)
{
	t_data			*data;
	int				philosopher_idx;
	struct timeval	now;

	data = info->parent_directory;
	philosopher_idx = info->philosopher_idx;
	data->philosophers[philosopher_idx].eating_count++;
	if (data->philosophers[philosopher_idx].eating_count >= data->rule.recursion_count)
	{
		pthread_mutex_lock(&(data->philosophers[philosopher_idx].status_key));
		data->philosophers[philosopher_idx].status = FULL;
		pthread_mutex_unlock(&(data->philosophers[philosopher_idx].status_key));
	}
	gettimeofday(&now, NULL);
	pthread_mutex_lock(&(info->status_key));
	info->status = EATING;
	pthread_mutex_unlock(&(info->status_key));
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
	pthread_mutex_lock(&(info->status_key));
	info->status = SLEEPING;
	pthread_mutex_unlock(&(info->status_key));
	print_message(data, &now, philosopher_idx, SLEEPING);
	usleep(data->rule.time_to_sleep * MILI_SEC);
	gettimeofday(&now, NULL);
	info->think_since = now;
	pthread_mutex_lock(&(info->status_key));
	info->status = THINKING;
	pthread_mutex_unlock(&(info->status_key));
	print_message(data, &now, philosopher_idx, THINKING);
	info->think_since = now;
}

void	*routine_philosopher(void *args)
{
	t_philosopher	*info;

	info = (t_philosopher *)args;
	while (1)
	{
		pthread_mutex_lock(&(info->status_key));
		if (info->status & (FULL | DEAD | ABORT))
			break ;
		pthread_mutex_unlock(&(info->status_key));
		pthread_mutex_lock(&(info->order_key));
		if (info->order == AUTHORIZED)
		{
			info->order = UNAUTHORIZED;
			pthread_mutex_unlock(&(info->order_key));
			grab(info->parent_directory, info->philosopher_idx);
			eat(info);
			release(info->parent_directory, info->philosopher_idx);
			sleep_and_think(info);
		}
		else
			pthread_mutex_unlock(&(info->order_key));
	}
	return (NULL);
}
