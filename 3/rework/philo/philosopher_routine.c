/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:27:26 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/18 15:59:10 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//for better reading, deadlock preventing will be handled at monitor by
//using mutex at critical section.
void	grab_fork(t_data *data, int philosopher_idx)
{
	int				left;
	int				right;
	struct timeval	now[2];

	left = get_next_index(data->rule.number_of_philosophers, philosopher_idx,
			-1);
	right = philosopher_idx;
	if (pthread_mutex_lock(&(data->forks[left])) != 0)
	{
		write(STDERR_FILENO, "pthread_mutex_lock() failed\n", 28);
		data->philosophers[philosopher_idx].status = _FUNCTIONAL_ERROR;
		interrupt_all_threads(data);
	}
	gettimeofday(&now[0], NULL);
	print_message(data, &now[0], philosopher_idx, TAKEN);
	if (pthread_mutex_lock(&(data->forks[right])) != 0)
	{
		write(STDERR_FILENO, "pthread_mutex_lock() failed\n", 28);
		data->philosophers[philosopher_idx].status = _FUNCTIONAL_ERROR;
		interrupt_all_threads(data);
	}
	gettimeofday(&now[1], NULL);
	print_message(data, &now[1], philosopher_idx, TAKEN);
}

void	eating(t_data *data, int philosopher_idx)
{
	struct timeval	now;

	data->philosophers->status = EATING;
	data->philosophers->eating_count++;
	gettimeofday(&now, NULL);
	print_message(data, &now, philosopher_idx, EATING);
	usleep(data->rule.time_to_eat * MILI_SEC);
}

void	put_fork(t_data *data, int philosopher_idx)
{
	int	left;
	int	right;

	left = get_next_index(data->rule.number_of_philosophers, philosopher_idx,
			-1);
	right = philosopher_idx;
	if (pthread_mutex_unlock(&(data->forks[left])) != 0)
	{
		write(STDERR_FILENO, "pthread_mutex_unlock() failed\n", 30);
		data->philosophers[philosopher_idx].status = _FUNCTIONAL_ERROR;
		interrupt_all_threads(data);
	}
	if (pthread_mutex_unlock(&(data->forks[right])) != 0)
	{
		write(STDERR_FILENO, "pthread_mutex_unlock() failed\n", 30);
		data->philosophers[philosopher_idx].status = _FUNCTIONAL_ERROR;
		interrupt_all_threads(data);
	}
}

void	sleeping_and_thinking(t_data *data, int philosopher_idx)
{
	struct timeval	now[2];

	data->philosophers[philosopher_idx].status = SLEEPING;
	gettimeofday(&now[0], NULL);
	print_message(data, &now[0], philosopher_idx, SLEEPING);
	usleep(data->rule.time_to_sleep * MILI_SEC);
	data->philosophers[philosopher_idx].status = THINKING;
	gettimeofday(&now[1], NULL);
	data->philosophers[philosopher_idx].think_since = now[1];
	print_message(data, &now[1], philosopher_idx, THINKING);
}

void	philosopher_status_check(t_data *data, int philosopher_idx)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	printf("hi\n");
	if (get_time_difference_in_ms
		(&(data->philosophers[philosopher_idx].think_since), &now)
		>= data->rule.time_to_die)
	{
		data->philosophers[philosopher_idx].status = DEAD;
		print_message(data, &now, philosopher_idx, DEAD);
		interrupt_all_threads(data);
	}
	if (data->rule.number_of_times_each_philosopher_must_eat)
	{
		if (data->philosophers[philosopher_idx].eating_count
			> data->rule.number_of_times_each_philosopher_must_eat)
		data->philosophers[philosopher_idx].status = FULL;
	}
	//is this behavior needed?
	//usleep(1 * MILI_SEC);
}
