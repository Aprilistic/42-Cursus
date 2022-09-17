/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:14 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/17 20:52:49 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		data_result;
	int		philosopher_idx;

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
	philosopher_idx = 0;
	while (philosopher_idx < data.rule.number_of_philosophers)
	{
		
	}
}
