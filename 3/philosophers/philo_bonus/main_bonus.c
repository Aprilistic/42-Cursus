/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:54:40 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/25 21:12:47 by jinheo           ###   ########.fr       */
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
	sem_wait(data.start_key);
	parent_process = fork_process(&data);
	if (parent_process)
	{
		if (control_process(&data))
			return (message_functional_error());
	}
	else
		wait_till_end();
	return (0);
}
