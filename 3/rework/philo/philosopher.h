/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:34 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/17 20:51:12 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// Error code
# define _INPUT_ERROR -1
# define _FUNCTIONAL_ERROR -2

// Order
# define UNAUTHORIZED 0
# define AUTHORIZED 1

// Status
# define TAKEN 1
# define EATING 2
# define SLEEPING 4
# define THINKING 8
# define FULL 16
# define DEAD 32

// Interrupt
# define FALSE 0
# define TRUE 1

// Milisecond
# define MILI_SEC 1000

// Color code
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define RESET "\x1B[0m"

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
	int				interrupt;
	int				eating_count;
	struct timeval	think_since;
}					t_philosopher;

typedef struct s_data
{
	t_rule			rule;
	t_philosopher	*philosophers;
	pthread_t		*monitors;
	pthread_t		*waiter;
	pthread_mutex_t	*forks;
	struct timeval	start_time;
}					t_data;

typedef struct s_args
{
	t_data			*data;
	int				philosopher_idx;
}					t_args;

// set.c
int					set_data(t_data *data, int argc, char *argv[]);

// delete.c
void				delete_data(t_data *data);

// initialize.c
void				initialize_process(t_data *data);

// utility.c
int					get_next_index(int max_index, int cur_index, int diff);
int					get_time_difference_in_ms(struct timeval *start,
						struct timeval *end);
void				interrupt_all_threads(t_data *data);

// philosopher_routine.c
void				grab_fork(t_data *data, int philosopher_idx);
void				eating(t_data *data, int philosopher_idx);
void				put_fork(t_data *data, int philosopher_idx);
void				sleeping_and_thinking(t_data *data, int philosopher_idx);
void				philosopher_status_check(t_data *data, int philosopher_idx);

// routine.c
void				philosopher_routine(void *args);
void				monitor_routine(void *args);
void				waiter_routine(void *args);


// print.c
void				print_message(t_data *data, struct timeval *now,
						int philosopher_idx, int mode);

#endif
