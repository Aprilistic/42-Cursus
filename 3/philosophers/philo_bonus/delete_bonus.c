/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/24 20:34:59 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

//mode forks : 1, print : 2, running : 4
int	delete_semaphore(t_data *data, int mode)
{
	int	error_flag;
	int	idx;

	error_flag = 0;
	idx = 0;
	if ((mode & 1) && sem_close(data->forks_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if ((mode & 2) && sem_close(data->print_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if ((mode & 4) && sem_close(data->running_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}

int	retrieve_resource(t_data *data)
{
	int	idx;
	int	ret;
	int	error_flag;

	idx = 0;
	ret = 0;
	error_flag = 0;
	while (idx < data->rule.number_of_philosophers)
	{
		ret |= waitpid(data->philosophers[idx].philosopher, NULL, 0);
		idx++;
	}
	if (ret == -1)
		error_flag |= write(STDERR_FILENO, "waitpid() failed.\n", 18);
	usleep(100 * MILI_SEC);
	error_flag |= delete_semaphore(data, 1 | 2 | 4);
	free(data->philosophers);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
