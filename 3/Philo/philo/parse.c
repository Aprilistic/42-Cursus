/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:20:44 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/12 15:25:53 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (-1);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret);
}

int	parse_argv(t_rule *data, int argc, char **argv)
{
	if (argc < 5 || 6 < argc)
		return (0);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_times_must_eat = 0;
	if (argc == 6)
		data->number_of_times_must_eat = ft_atoi(argv[5]);
	if (data->number_of_philosophers | data->time_to_die | data->time_to_eat
		| data->time_to_sleep | data->number_of_times_must_eat < 0)
		return (0);
	return (1);
}
