/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/25 20:37:59 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

//mode forks : 1, print : 2, start : 4
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
	if ((mode & 4) && sem_close(data->start_key))
			error_flag |= write(STDERR_FILENO, "sem_close failed\n", 17);
	if (error_flag)
		return (_FUNCTIONAL_ERROR);
	return (0);
}
