/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:05:19 by jinheo            #+#    #+#             */
/*   Updated: 2022/12/05 17:18:40 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	dead_check(t_philosopher *info)
{
	t_data			*data;
	struct timeval	last_status_change;
	struct timeval	now;

	data = info->parent_directory;
	gettimeofday(&now, NULL);
	while (1)
	{
		if (!info->time_key)
		{
			info->time_key = 1;
			last_status_change = info->last_status_change;
			info->time_key = 0;
			break ;
		}
	}
	if (get_time_difference_in_ms(&last_status_change,
			&now) >= data->rule.time_to_die
		&& info->eating_count < data->rule.recursion_count)
	{
		print_message(data, &now, info->philosopher_idx, DEAD);
		return (1);
	}
	return (0);
}

void	*routine_monitor(void *args)
{
	t_philosopher	*info;

	info = (t_philosopher *)args;
	wait_till_begin(info);
	while (1)
	{
		if (dead_check(info))
			exit(DEAD);
		usleep(700);
	}
}
