/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:04:07 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/12 15:37:55 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EATING 	0
# define THINKING	1
# define SLEEPING	2
# define DEAD		3

typedef struct s_rule
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_must_eat;
}				t_rule;

typedef struct s_philo
{
	int			last_eat;
	int			last_think;
	int			last_sleep;
	int			status;
	int			eat_count;
	pthread_t	philosopher;
}				t_philo;

int				parse_argv(t_rule *data, int argc, char **argv);

void			lets_eat_think_sleep(t_rule *data);

#endif
