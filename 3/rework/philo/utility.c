/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:55:01 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/17 16:38:46 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_next_index(int max_index, int cur_index, int diff)
{
	return ((cur_index + diff + max_index) % max_index);
}

int	get_time_difference_in_ms(struct timeval *start, struct timeval *end)
{
	int	time_difference_in_ms;

	time_difference_in_ms = (end->tv_sec - start->tv_sec) * 1000
		+ (end->tv_usec - start->tv_usec) / 1000;
	return ((int)time_difference_in_ms);
}

void	interrupt_all_threads(t_data *data)
{
	int	thread_idx;

	thread_idx = 0;
	while (thread_idx < data->rule.number_of_philosophers)
	{
		data->philosophers[thread_idx].interrupt = TRUE;
		thread_idx++;
	}
}
