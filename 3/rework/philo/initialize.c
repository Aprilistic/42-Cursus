/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:44:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/18 15:54:44 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	initialize_process(t_data *data)
{
	struct timeval	start_time;
	int				philosopher_idx;

	gettimeofday(&start_time, NULL);
	data->start_time = start_time;
	philosopher_idx = 0;
	while (philosopher_idx < data->rule.number_of_philosophers)
	{
		data->philosophers[philosopher_idx].order = UNAUTHORIZED;
		data->philosophers[philosopher_idx].status = THINKING;
		data->philosophers[philosopher_idx].interrupt = FALSE;
		data->philosophers[philosopher_idx].eating_count = 0;
		data->philosophers[philosopher_idx].think_since = start_time;
		philosopher_idx++;
	}
}

static int	initialize_monitors(t_data *data)
{
	t_args	*args;
	int		monitor_idx;

	monitor_idx = 0;
	while (monitor_idx < data->rule.number_of_philosophers)
	{
		args = (t_args *)malloc(sizeof(t_args));
		if (args == NULL)
		{
			write(STDERR_FILENO, "malloc() failed.\n", 17);
			return (_FUNCTIONAL_ERROR);
		}
		args->data = data;
		args->philosopher_idx = monitor_idx;
		printf("monitor entered\n");
		if (pthread_create(&(data->monitors[monitor_idx]), NULL,
				monitor_routine, &args) != 0)
		{
			write(STDERR_FILENO, "pthread_create() failed.\n", 25);
			return (_FUNCTIONAL_ERROR);
		}
		monitor_idx++;
		//error can occur
		free(args);
	}
	return (0);
}

static int	initialize_waiter(t_data *data)
{
		printf("waiter entered\n");
	if (pthread_create(data->waiter, NULL, waiter_routine, data) != 0)
	{
		write(STDERR_FILENO, "pthread_create() failed.\n", 25);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}

static int	initialize_philosophers(t_data *data)
{
	t_args	*args;
	int		philosopher_idx;

	philosopher_idx = 0;
	while (philosopher_idx < data->rule.number_of_philosophers)
	{
		args = (t_args *)malloc(sizeof(t_args));
		if (args == NULL)
		{
			write(STDERR_FILENO, "malloc() failed.\n", 17);
			return (_FUNCTIONAL_ERROR);
		}
		args->data = data;
		args->philosopher_idx = philosopher_idx;
		printf("philosoper entered\n");
		if (pthread_create(&(data->philosophers[philosopher_idx].philosopher),
				NULL, philosopher_routine, &args) != 0)
		{
			write(STDERR_FILENO, "pthread_create() failed.\n", 25);
			return (_FUNCTIONAL_ERROR);
		}
		philosopher_idx++;
		//error can occur
		free(args);
	}
	return (0);
}

int	initialize_threads(t_data *data)
{
	if (initialize_philosophers(data) == _FUNCTIONAL_ERROR
		|| initialize_monitors(data) == _FUNCTIONAL_ERROR
		|| initialize_waiter(data) == _FUNCTIONAL_ERROR)
	{
		interrupt_all_threads(data);
		return (_FUNCTIONAL_ERROR);
	}
	return (0);
}
