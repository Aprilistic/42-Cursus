/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:14 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 14:00:49 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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

int	main(int argc, char *argv[])
{
	t_data	data;
	int		data_result;

	data_result = set_data(&data, argc, argv);
	if (data_result == _INPUT_ERROR)
		return (message_input_error());
	else if (data_result == _FUNCTIONAL_ERROR)
		return (message_functional_error());
	if (set_mutex(&data) == _FUNCTIONAL_ERROR)
		return (message_functional_error());
	if (run_threads(&data) == _FUNCTIONAL_ERROR)
		return (message_functional_error());
	usleep(1000 * MILI_SEC);
	pthread_join(data.waiter, NULL);
	return (0);
}
