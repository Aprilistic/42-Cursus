/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:52:15 by jinheo            #+#    #+#             */
/*   Updated: 2022/12/03 18:07:18 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	get_time_difference_in_ms(struct timeval *start, struct timeval *end)
{
	return ((((end->tv_sec - start->tv_sec) * 1000000)
			+ (end->tv_usec - start->tv_usec)) / 1000);
}

void	wait_till(struct timeval *start, int duration)
{
	struct timeval	now;

	while (1)
	{
		gettimeofday(&now, NULL);
		if (get_time_difference_in_ms(start, &now) >= duration)
			break ;
		usleep(150);
	}
}

void	update_timestamp(t_philosopher *info, struct timeval *now)
{
	while (1)
	{
		if (!info->time_key)
		{
			info->time_key = 1;
			info->last_status_change = *now;
			info->time_key = 0;
			break ;
		}
	}
}

void	print_message(t_data *data, struct timeval *now, int philosopher_idx,
		int mode)
{
	int	timestamp;

	sem_wait(data->print_key);
	timestamp = get_time_difference_in_ms(&(data->start_time), now);
	if (mode == TAKEN)
		printf(YEL "%d %d has taken a fork\n" RESET, timestamp, philosopher_idx
			+ 1);
	else if (mode == EATING)
		printf(WHT "%d %d is eating\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == SLEEPING)
		printf(BLU "%d %d is sleeping\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == THINKING)
		printf(GRN "%d %d is thinking\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == DEAD)
	{
		printf(RED "%d %d died\n" RESET, timestamp, philosopher_idx + 1);
		exit(DEAD);
	}
	sem_post(data->print_key);
}
