/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:52:15 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/19 17:27:49 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_next_index(int max_index, int cur_index, int offset)
{
	return ((cur_index + max_index + offset) % max_index);
}

int	get_time_difference_in_ms(struct timeval *start, struct timeval *end)
{
	int	time_difference_in_ms;

	time_difference_in_ms = (end->tv_sec - start->tv_sec) * 1000
		+ (end->tv_usec - start->tv_usec) / 1000;
	return ((int)time_difference_in_ms);
}

void	print_message(t_data *data, struct timeval *now, int philosopher_idx,
		int mode)
{
	int	timestamp;

	pthread_mutex_lock(&(data->print_key));
	timestamp = get_time_difference_in_ms(&(data->start_time), now);
	if (mode == TAKEN)
		printf(YEL "%d %d has taken a fork\n" RESET, timestamp, philosopher_idx
			+ 1);
	else if (mode == EATING)
		printf(WHT "%d %d is eating\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == SLEEPING)
		printf(BLU "%d %d is sleeping\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == THINKING)
		printf(CYN "%d %d is thinking\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == DEAD)
		printf(RED "%d %d died\n" RESET, timestamp, philosopher_idx + 1);
	pthread_mutex_unlock(&(data->print_key));
}
