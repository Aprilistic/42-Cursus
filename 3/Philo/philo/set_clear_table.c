/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clear_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:57:28 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/12 15:38:28 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_forks(t_rule *data, pthread_mutex_t *forks)
{
	int	idx;
	int	errno;
	int	tmp;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!forks)
		return (1);
	idx = 0;
	while (idx < data->number_of_philosophers)
	{
		errno = pthread_mutex_init(forks + idx, NULL);
		if (errno)
		{
			tmp = 0;
			while (tmp < idx)
			{
				pthread_mutex_destroy(&forks[tmp]);
				tmp++;
			}
			return (errno);
		}
		idx++;
	}
	return (0);
}

static int	clear_forks(t_rule *data, pthread_mutex_t *forks)
{
	int	idx;
	int	errno;

	errno = 0;
	idx = 0;
	while (idx < data->number_of_philosophers)
	{
		errno |= pthread_mutex_destroy(&forks[idx]);
		idx++;
	}
	free(forks);
	return (errno);
}

void	lets_eat_think_sleep(t_rule *data)
{
	t_philo			*philosophers;
	pthread_mutex_t	*forks;

	if (set_forks(data, forks))
	{
		write(STDERR_FILENO, "Failed to set forks... Bye.\n", 28);
		return ;
	}
	philosophers
		= (t_philo *)malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!philosophers)
		write(STDERR_FILENO, "Failed to set philosophers...\n", 30);
	else
		do_something();
	if (philosophers)
		free(philosophers);
	if (clear_forks(data, forks))
	{
		write(STDERR_FILENO,
			"Hmm... Something's wrong with mutex_destroy().\n", 47);
	}
}
