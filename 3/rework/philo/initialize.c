/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:44:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/17 21:10:28 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	initialize_process(t_data *data)
{
	struct timeval	start_time;
	int				philosopher_idx;

	gettimeofday(&start_time, NULL);
	data->start_time = start_time;
	philosopher_idx = 0;
	while (philosopher_idx < data->rule.number_of_philosophers)
	{
		data->philosophers[philosopher_idx].order = UNAUTHORIZED;
		data->philosophers[philosopher_idx].status = THINKING;
		data->philosophers[philosopher_idx].interrupt = FALSE;
		data->philosophers[philosopher_idx].eating_count = 0;
		data->philosophers[philosopher_idx].think_since = start_time;
		philosopher_idx++;
	}
}


int	initialize_threads(t_data *data)
{
	int	philosopher_idx;
	
	initialize_monitors();
	initialize_waiter();
	initialize_philosophers();
	return (0);
}
