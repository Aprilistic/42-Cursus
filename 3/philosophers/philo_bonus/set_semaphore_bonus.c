/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_semaphore_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:02:27 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/23 21:29:18 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	sem_open_fail(void)
{
	write(STDERR_FILENO, "sem_open failed.\n", 17);
	return (_FUNCTIONAL_ERROR);
}

int	set_semaphore(t_data *data)
{
	int	idx;

	idx = 0;
	data->forks_key = sem_open("forks", O_CREAT | O_EXCL, 0644,
			data->rule.number_of_philosophers);
	if (data->forks_key == SEM_FAILED)
	{
		return (sem_open_fail());
	}
	data->print_key = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (data->print_key == SEM_FAILED)
	{
		delete_semaphore(data, 1);
		return (sem_open_fail());
	}
	data->running_key = sem_open("running", O_CREAT | O_EXCL, 0644, 1);
	if (data->running_key == SEM_FAILED)
	{
		delete_semaphore(data, 1 | 2);
		return (sem_open_fail());
	}
	return (0);
}
