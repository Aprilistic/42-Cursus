/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:34 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/16 17:05:30 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// Error code
# define _INPUT_ERROR		-1
# define _FUNCTIONAL_ERROR	-2

// Order
# define AUTHORIZED		1
# define UNAUTHORIZED	0

// Status
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define FULL		4
# define DEAD		5

// Milisecond
# define MILI_SEC	1000

typedef struct s_rule
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_rule;

typedef struct s_philosopher
{
	pthread_t		philosopher;
	int				order;
	int				status;
	int				eating_count;
	struct timeval	hungry_since;
}					t_philosopher;

typedef struct s_data
{
	t_rule			rule;
	t_philosopher	*philosophers;
	pthread_t		*monitors;
	pthread_t		*waiter;
	pthread_mutex_t	*forks;
}					t_data;

// set.c
int					set_data(t_data *data, int argc, char *argv[]);

// delete.c
void				delete_data(t_data *data);

#endif
