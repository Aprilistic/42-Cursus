/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:52:15 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/24 19:01:29 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

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
	info->last_status_change = *now;
}

void	print_message(t_data *data, struct timeval *now, int philosopher_idx,
		int mode)
{
	int	timestamp;

	if (!running_status_check(data))
		return ;
	sem_wait(data->print_key);
	timestamp = get_time_difference_in_ms(&(data->start_time), now);
	if (mode == TAKEN && running_status_check(data))
		printf(YEL "%d %d has taken a fork\n" RESET, timestamp, philosopher_idx
			+ 1);
	else if (mode == EATING && running_status_check(data))
		printf(WHT "%d %d is eating\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == SLEEPING && running_status_check(data))
		printf(BLU "%d %d is sleeping\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == THINKING && running_status_check(data))
		printf(GRN "%d %d is thinking\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == DEAD && running_status_check(data))
	{
		running_status_change(data, 0);
		printf(RED "%d %d died\n" RESET, timestamp, philosopher_idx + 1);
	}
	sem_post(data->print_key);
}
