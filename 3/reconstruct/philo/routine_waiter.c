/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:13:21 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/19 17:41:32 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	overall_check(t_data *data, int philosopher_idx, int max_idx)
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
		if (idx == get_next_index(max_idx, philosopher_idx, -1)
			|| idx == get_next_index(max_idx, philosopher_idx, 1))
			nearby |= data->philosophers[idx].status;
		pthread_mutex_unlock(&(data->philosophers[idx].status_key));
		idx++;
	}
	if (abort & (ABORT | DEAD) || full)
		return (STOP);
	else if (nearby & EATING)
		return (WAIT);
	return (GO);
}

static void	give_permission(t_philosopher *target)
{
	printf("trying to give permission\n");
	pthread_mutex_lock(&(target->order_key));
	target->order = AUTHORIZED;
	pthread_mutex_unlock(&(target->order_key));
	printf("successfully gave permission\n");
}

void	*routine_waiter(void *args)
{
	t_data	*data;
	int		idx;
	int		result;
	int		odd;

	data = (t_data *)args;
	idx = 0;
	odd = data->rule.number_of_philosophers % 2;
	while (1)
	{
		if (odd && idx == 1)
			idx--;
		else if (odd && idx == 0)
			idx++;
		result = overall_check(data, idx, data->rule.number_of_philosophers);
		if (result == STOP)
			break ;
		else if (result == WAIT)
			continue ;
		else if (result == GO)
			give_permission(&(data->philosophers[idx]));
		idx = get_next_index(data->rule.number_of_philosophers, idx, 2);
	}
	return (NULL);
}
