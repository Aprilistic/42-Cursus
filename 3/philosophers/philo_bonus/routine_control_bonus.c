/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_control_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:40:24 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/25 21:50:01 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	wait_till_begin(t_philosopher *info)
{
	struct timeval	now;

	sem_wait(info->parent_directory->start_key);
	sem_post(info->parent_directory->start_key);
	gettimeofday(&now, NULL);
	info->last_status_change = now;
	info->parent_directory->start_time = now;
}

void	wait_till_end(void)
{
	while (1)
	{
	}
}

static void	begin_supper(t_data *data)
{
	int				idx;
	struct timeval	now;

	gettimeofday(&now, NULL);
	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers[idx].last_status_change = now;
		idx++;
	}
	data->start_time = now;
	sem_post(data->start_key);
}

void	kill_all_child_processes(t_data *data, pid_t except)
{
	int	idx;

	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		if (data->philosophers[idx].philosopher != except)
			kill(data->philosophers[idx].philosopher, SIGTERM);
		idx++;
	}
}

int	control_process(t_data *data)
{
	int	retrieved_count;
	int	ret;
	int	error_flag;
	int	status;

	error_flag = 0;
	retrieved_count = 0;
	ret = 0;
	begin_supper(data);
	while (retrieved_count < data->rule.number_of_philosophers)
	{
		ret = waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == DEAD)
		{
			kill_all_child_processes(data, ret);
			break ;
		}
		retrieved_count++;
	}
	usleep(100 * MILI_SEC);
	error_flag |= delete_semaphore(data, 1 | 2 | 4);
	free(data->philosophers);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
