/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:13:21 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 14:10:39 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	initiate_process(t_data *data)
{
	int				idx;

	idx = 0;
	gettimeofday(&(data->start_time), NULL);
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers[idx].think_since = data->start_time;
		pthread_mutex_lock(&(data->philosophers[idx].status_key));
		data->philosophers[idx].status = THINKING;
		pthread_mutex_unlock(&(data->philosophers[idx].status_key));
		idx++;
	}
}

static int	overall_check(t_data *data, int cur_idx, int prev_idx, int max_idx)
{
	int	idx;
	int	abort;
	int	full;
	int	nearby;

	idx = 0;
	abort = 0;
	full = FULL;
	nearby = 0;
	while (idx < max_idx)
	{
		pthread_mutex_lock(&(data->philosophers[idx].status_key));
		abort |= data->philosophers[idx].status;
		full &= data->philosophers[idx].status;
		if (idx == get_next_index(max_idx, cur_idx, -1)
			|| idx == get_next_index(max_idx, cur_idx, 1))
			nearby |= data->philosophers[idx].status;
		pthread_mutex_unlock(&(data->philosophers[idx].status_key));
		idx++;
	}
	if (abort & (ABORT | DEAD) || full)
		return (STOP);
	else if ((nearby & (EATING | WAITING)) || (prev_idx != -1
		&& data->philosophers[prev_idx].eating_count
		== data->philosophers[cur_idx].eating_count))
		return (WAIT);
	return (GO);
}

static void	give_permission(t_philosopher *target)
{
	pthread_mutex_lock(&(target->order_key));
	target->order = AUTHORIZED;
	pthread_mutex_unlock(&(target->order_key));
}

void	*routine_waiter(void *args)
{
	t_data	*data;
	int		cur_idx;
	int		prev_idx;
	int		result;
	int		odd;

	data = (t_data *)args;
	initiate_process(data);
	cur_idx = 0;
	prev_idx = -1;
	odd = data->rule.number_of_philosophers % 2;
	while (1)
	{
		if (odd && cur_idx == 1)
			cur_idx--;
		else if (odd && cur_idx == 0)
			cur_idx++;
		result = overall_check(data, cur_idx, prev_idx,
				data->rule.number_of_philosophers);
		if (result == STOP)
			break ;
		else if (result == WAIT)
			continue ;
		else if (result == GO)
			give_permission(&(data->philosophers[cur_idx]));
		prev_idx = cur_idx;
		cur_idx = get_next_index(data->rule.number_of_philosophers, cur_idx, 2);
	}
	return (NULL);
}
