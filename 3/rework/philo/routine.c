/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:54:17 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/17 20:22:18 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philosopher_routine(void *args)
{
	t_data	*data;
	int		philosopher_idx;

	data = ((t_args *)args)->data;
	philosopher_idx = ((t_args *)args)->philosopher_idx;
	while (1)
	{
		philosopher_status_check(data, philosopher_idx);
		if (data->philosophers[philosopher_idx].interrupt == TRUE
			|| data->philosophers[philosopher_idx].status == FULL)
			break ;
		if (data->philosophers[philosopher_idx].order == AUTHORIZED)
		{
			data->philosophers[philosopher_idx].order == UNAUTHORIZED;
			grab_fork(data, philosopher_idx);
			eating(data, philosopher_idx);
			put_fork(data, philosopher_idx);
			sleeping_and_thinking(data, philosopher_idx);
		}
	}
}

void	monitor_routine(void *args)
{
	t_data	*data;
	int		philosopher_idx;

	data = ((t_args *)args)->data;
	philosopher_idx = ((t_args *)args)->philosopher_idx;
	while (1)
	{
		if (data->philosophers[philosopher_idx].status == DEAD
			|| data->philosophers[philosopher_idx].status == _FUNCTIONAL_ERROR)
		{
			interrupt_all_threads(data);
			break ;
		}
		if (data->philosophers[philosopher_idx].interrupt == TRUE)
			break ;
		//is this actually needed?
		usleep(1 * MILI_SEC);
	}
}

static void	wait_for_neighbor_philosophers(t_data *data, int philosopher_idx)
{
	int	left;
	int	right;

	left = get_next_index(data->rule.number_of_philosophers, philosopher_idx,
			-1);
	right = get_next_index(data->rule.number_of_philosophers, philosopher_idx,
			1);
	while (1)
	{
		if (data->philosophers[left].status != EATING
			&& data->philosophers[left].order == UNAUTHORIZED
			&& data->philosophers[right].status != EATING
			&& data->philosophers[right].order == UNAUTHORIZED)
			break ;
	}
}

static int	interrupt_occurred(t_data *data)
{
	int	philosopher_idx;

	philosopher_idx = 0;
	while (philosopher_idx < data->rule.number_of_philosophers)
	{
		if (data->philosophers[philosopher_idx].interrupt == TRUE)
			return (TRUE);
		philosopher_idx++;
	}
	return (FALSE);
}

void	waiter_routine(void *args)
{
	t_data	*data;
	int		turn;
	int		max_parallel_threads;
	int		parallel_idx;
	int		philosopher_idx;

	data = ((t_args *)args)->data;
	turn = 1;
	max_parallel_threads = data->rule.number_of_philosophers / 2;
	while (1)
	{
		parallel_idx = 0;
		while (parallel_idx < max_parallel_threads)
		{
			philosopher_idx = get_next_index(data->rule.number_of_philosophers,
					turn, parallel_idx * 2);
			wait_for_neighbor_philosophers(data, philosopher_idx);
			if (data->philosophers[philosopher_idx].status == THINKING)
				data->philosophers[philosopher_idx].order = AUTHORIZED;
			if (interrupt_occurred(data))
				break ;
			parallel_idx++;
		}
		turn = get_next_index(data->rule.number_of_philosophers, turn, -1);
	}
}
