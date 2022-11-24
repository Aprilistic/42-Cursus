/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:54:40 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/24 21:20:41 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	message_input_error(void)
{
	write(STDOUT_FILENO, "Invalid input. Exit process.\n", 29);
	return (0);
}

static int	message_functional_error(void)
{
	write(STDERR_FILENO, "Functional error occurred. Terminate process.\n", 46);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		data_result;
	int		idx;
	int		parent_process;

	data_result = set_data(&data, argc, argv);
	if (data_result == _INPUT_ERROR)
		return (message_input_error());
	else if (data_result == _FUNCTIONAL_ERROR)
		return (message_functional_error());
	if (set_semaphore(&data) == _FUNCTIONAL_ERROR)
	{
		free(data.philosophers);
		return (message_functional_error());
	}
	parent_process = 1;
	idx = 0;
	while (idx < data.rule.number_of_philosophers)
	{
		data.philosophers[idx].philosopher = fork();
		if (data.philosophers[idx].philosopher == 0)
		{
			parent_process = 0;
			run_thread(&data.philosophers[idx]);
			break ;
		}
		idx++;
	}
	if (parent_process){
		struct timeval now;
		gettimeofday(&now, NULL);
		for (int i=0; i<data.rule.number_of_philosophers; ++i){
			data.philosophers[i].last_status_change = now;
		}
		data.start_time = now;
		sem_wait(data.running_key);
		data.running = 1;
		sem_post(data.running_key);
		printf("running status is on\n");
		if (retrieve_resource(&data))
			return (message_functional_error());}
	if (!parent_process)
		while (1){}
	return (0);
}
