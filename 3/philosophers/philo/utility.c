/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:52:15 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/22 18:00:59 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_time_difference_in_ms(struct timeval *start, struct timeval *end)
{
	int	time_difference_in_ms;

	time_difference_in_ms = (end->tv_sec - start->tv_sec) * 1000 + (end->tv_usec
			- start->tv_usec) / 1000;
	return ((int)time_difference_in_ms);
}

void	wait_till(struct timeval *start, int duration)
{
	struct timeval	now;

	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_difference_in_ms(start, &now) >= duration)
			break ;
		usleep(900);
	}
}

void	update_timestamp(t_philosopher *info, struct timeval *now)
{
	pthread_mutex_lock(&info->time_key);
	info->last_status_change = *now;
	pthread_mutex_unlock(&info->time_key);
}

void	print_message(t_data *data, struct timeval *now, int philosopher_idx,
		int mode)
{
	int	timestamp;

	if (!running_status_check(data))
		return ;
	pthread_mutex_lock(&(data->print_key));
	timestamp = get_time_difference_in_ms(&(data->start_time), now);
	if (mode == TAKEN && data->running)
		printf(YEL "%d %d has taken a fork\n" RESET, timestamp, philosopher_idx
			+ 1);
	else if (mode == EATING && data->running)
		printf(WHT "%d %d is eating\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == SLEEPING && data->running)
		printf(BLU "%d %d is sleeping\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == THINKING && data->running)
		printf(GRN "%d %d is thinking\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == DEAD && data->running)
	{
		running_status_change(data, 0);
		printf(RED "%d %d died\n" RESET, timestamp, philosopher_idx + 1);
	}
	pthread_mutex_unlock(&(data->print_key));
}

int	solo_deadlock_exception(t_data *data)
{
	if (data->rule.number_of_philosophers != 1)
		return (0);
	usleep(data->rule.time_to_die * MILI_SEC);
	pthread_mutex_unlock(&data->forks_key[0]);
	return (1);
}
