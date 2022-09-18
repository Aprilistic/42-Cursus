/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:14 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/18 15:38:03 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		data_result;

	data_result = set_data(&data, argc, argv);
	if (data_result == _INPUT_ERROR)
	{
		write(STDOUT_FILENO, "Invalid input. Exit Process.\n", 29);
		return (0);
	}
	else if (data_result == _FUNCTIONAL_ERROR)
	{
		write(STDERR_FILENO, "Functional error occurred. Terminate process.\n",
				46);
		return (1);
	}
	initialize_process(&data);
	if (initialize_threads(&data) == _FUNCTIONAL_ERROR)
	{
		write(STDERR_FILENO, "Functional error occurred. Terminate process.\n",
				46);
		delete_data(&data);
		return (1);
	}
	if (delete_threads(&data) == _FUNCTIONAL_ERROR)
	{
		write(STDERR_FILENO, "Functional error occurred. Terminate process.\n",
				46);
		delete_data(&data);
		return (1);
	}
	delete_data(&data);
	return (0);
}
