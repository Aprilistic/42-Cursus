/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:18:20 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 19:16:06 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	begin_supper(t_data *data)
{
	int				idx;
	struct timeval	now;

	idx = 0;
	gettimeofday(&now, NULL);
	data->start_time = now;
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers->starved_since = now;
		idx++;
	}
	data->running = 1;
}

static int	full_check(t_data *data)
{
	int	idx;
	int	all_full;

	idx = 0;
	all_full = 1;
	while (idx < data->rule.number_of_philosophers)
	{
		if (data->philosophers[idx].eating_count < data->rule.recursion_count)
		{
			all_full = 0;
			break ;
		}
		idx++;
	}
	return (all_full);
}

void	*routine_monitor(void *args)
{
	t_data			*data;
	int				idx;
	struct timeval	now;

	data = (t_data *)args;
	begin_supper(data);
	while (data->running)
	{
		gettimeofday(&now, NULL);
		idx = 0;
		while (idx < data->rule.number_of_philosophers)
		{
			if (full_check(data))
				return (NULL);
			if (get_time_difference_in_ms(&data->philosophers[idx].starved_since,
					&now) >= data->rule.time_to_die)
			{
				print_message(data, &now, idx, DEAD);
				break ;
			}
			idx++;
		}
		usleep(700);
	}
	return (NULL);
}
