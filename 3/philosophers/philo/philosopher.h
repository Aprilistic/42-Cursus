/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:34 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/20 17:30:52 by jinheo           ###   ########.fr       */
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
# define _INPUT_ERROR -1
# define _FUNCTIONAL_ERROR -2

// Status
# define TAKEN 1
# define EATING 2
# define SLEEPING 4
# define THINKING 8
# define FULL 16
# define DEAD 32

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
	int				recursion_count;
}					t_rule;

typedef struct s_data	t_data;

typedef struct s_philosopher
{
	t_data			*parent_directory;
	pthread_t		philosopher;
	int				philosopher_idx;
	int				eating_count;
	struct timeval	starved_since;
}					t_philosopher;

typedef struct s_data
{
	t_rule			rule;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks_key;
	int				*forks;
	pthread_t		monitor;
	pthread_mutex_t	print_key;
	struct timeval	start_time;
	int				running;
}					t_data;

// set_*.c
int					set_data(t_data *data, int argc, char *argv[]);
int					set_mutex(t_data *data);

// run.c
int					run_threads(t_data *data);

// utility.c
int					get_next_index(int max_index, int cur_index, int offset);
int					get_time_difference_in_ms(struct timeval *start,
						struct timeval *end);
void				print_message(t_data *data, struct timeval *now,
						int philosopher_idx, int mode);

// routine_*.c
void				*routine_philosopher(void *args);
void				*routine_monitor(void *args);

// delete.c
void				delete_data(t_data *data);
int					delete_mutex(t_data *data, int mode);
void				induce_thread_exit(t_data *data);
int					retrieve_resource(t_data *data);

#endif