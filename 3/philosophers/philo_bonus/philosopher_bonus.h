/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:34 by jinheo            #+#    #+#             */
/*   Updated: 2022/12/03 20:46:52 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>

// Error code
# define _INPUT_ERROR -1
# define _FUNCTIONAL_ERROR -2

// Status
# define TAKEN 1
# define EATING 2
# define SLEEPING 4
# define THINKING 8
# define DEAD 16

// Time macro
# define MILI_SEC 1000
# define SLEEP_FACTOR 0.7

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
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					recursion_count;
}						t_rule;

typedef struct s_data	t_data;

typedef struct s_philosopher
{
	t_data				*parent_directory;
	pid_t				philosopher;
	int					philosopher_idx;
	int					eating_count;
	_Atomic int			time_key;
	struct timeval		last_status_change;
}						t_philosopher;

typedef struct s_data
{
	t_rule				rule;
	sem_t				*start_key;
	sem_t				*forks_key;
	sem_t				*print_key;
	t_philosopher		*philosophers;
	struct timeval		start_time;
}						t_data;

// set_*.c
int						set_data(t_data *data, int argc, char *argv[]);
int						set_semaphore(t_data *data);

// run.c
void					run_thread(t_philosopher *info);
int						fork_process(t_data *data);

// utility.c
int						get_time_difference_in_ms(struct timeval *start,
							struct timeval *end);
void					wait_till(struct timeval *start, int duration);
void					update_timestamp(t_philosopher *info,
							struct timeval *now);
void					print_message(t_data *data, struct timeval *now,
							int philosopher_idx, int mode);

// routine_*.c
void					*routine_philosopher(void *args);
void					*routine_monitor(void *args);
void					wait_till_begin(t_philosopher *info);
void					wait_till_end(void);
int						control_process(t_data *data);

// delete.c
int						delete_semaphore(t_data *data, int mode);

#endif
