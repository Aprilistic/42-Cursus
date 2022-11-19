/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:18:20 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/19 17:40:47 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	initiate_process(t_data *data)
{
	int				idx;
	struct timeval	init_time;

	idx = 0;
	gettimeofday(&init_time, NULL);
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers[idx].think_since = init_time;
		pthread_mutex_lock(&(data->philosophers[idx].status_key));
		data->philosophers[idx].status = THINKING;
		pthread_mutex_unlock(&(data->philosophers[idx].status_key));
		idx++;
	}
}

void	*routine_monitor(void *args)
{
	t_data			*data;
	int				idx;
	struct timeval	now;

	data = (t_data *)args;
	initiate_process(data);
	while (1)
	{
		gettimeofday(&now, NULL);
		idx = 0;
		while (idx < data->rule.number_of_philosophers)
		{
			pthread_mutex_lock(&(data->philosophers[idx].status_key));
			if ((data->philosophers[idx].status & (WAITING | FULL)) == 0
				&& get_time_difference_in_ms(
					&(data->philosophers[idx].think_since),
					&now) >= data->rule.time_to_die)
			{
				print_message(data, &now, idx, DEAD);
				kill_switch(data);
				break ;
			}
		}
	}
	return (NULL);
}
