/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:18:20 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 14:21:37 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine_monitor(void *args)
{
	t_data			*data;
	int				idx;
	struct timeval	now;
	int				status;

	data = (t_data *)args;
	while (1)
	{
		gettimeofday(&now, NULL);
		idx = 0;
		while (idx < data->rule.number_of_philosophers)
		{
			pthread_mutex_lock(&(data->philosophers[idx].status_key));
			status = data->philosophers[idx].status;
			pthread_mutex_unlock(&(data->philosophers[idx].status_key));
			if ((status & (WAITING | FULL)) == 0
				&& get_time_difference_in_ms(
					&(data->philosophers[idx].think_since),
					&now) >= data->rule.time_to_die)
			{
				print_message(data, &now, idx, DEAD);
				kill_switch(data);
				break ;
			}
			idx++;
		}
	}
	return (NULL);
}
