/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_semaphore_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:02:27 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/24 20:36:26 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	sem_open_fail(t_data *data, int mode)
{
	write(STDERR_FILENO, "sem_open failed.\n", 17);
	delete_semaphore(data, mode);
	return (_FUNCTIONAL_ERROR);
}

static int	sem_unlink_fail(t_data *data, int mode)
{
	write(STDERR_FILENO, "sem_unlink failed.\n", 19);
	delete_semaphore(data, mode);
	return (_FUNCTIONAL_ERROR);
}

int	set_semaphore(t_data *data)
{
	int	idx;

	idx = 0;
	data->forks_key = sem_open("forks", O_CREAT | O_EXCL, 0644,
			data->rule.number_of_philosophers);
	if (data->forks_key == SEM_FAILED)
		return (sem_open_fail(data, 0));
	if (sem_unlink("forks"))
		return (sem_unlink_fail(data, 0));
	data->print_key = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (data->print_key == SEM_FAILED)
		return (sem_open_fail(data, 1));
	if (sem_unlink("print"))
		return (sem_unlink_fail(data, 1));
	data->running_key = sem_open("running", O_CREAT | O_EXCL, 0644, 1);
	if (data->running_key == SEM_FAILED)
		return (sem_open_fail(data, 1 | 2));
	if (sem_unlink("running"))
		return (sem_unlink_fail(data, 1 | 2));
	return (0);
}
