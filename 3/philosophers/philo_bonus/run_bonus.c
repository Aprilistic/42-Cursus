/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:10:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/25 19:38:16 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	fork_process(t_data *data)
{
	int	parent_process;
	int	idx;

	parent_process = 1;
	idx = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		data->philosophers[idx].philosopher = fork();
		if (data->philosophers[idx].philosopher == 0)
		{
			parent_process = 0;
			run_thread(&data->philosophers[idx]);
			break ;
		}
		idx++;
	}
	return (parent_process);
}

void	run_thread(t_philosopher *info)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &routine_philosopher, info))
	{
		write(STDERR_FILENO, "pthread_create() failed.\n", 25);
		exit(_FUNCTIONAL_ERROR);
	}
}
